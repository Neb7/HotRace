/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:32:41 by benpicar          #+#    #+#             */
/*   Updated: 2025/12/08 17:11:01 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief	Reads a line from a file descriptor.
 * 
 * @param	fd The file descriptor to read from.
 * @return	A pointer to the read line, or NULL on failure.
 */
char	*get_next_line(int fd)
{
	static t_buffer	*buffer = NULL;
	t_buffer		*actual;
	char			*d;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	d = NULL;
	if (!buffer)
		buffer = ft_new_struct(fd);
	if (!buffer)
		return (ft_free_all(&buffer, buffer, NULL, NULL), free(d), NULL);
	actual = ft_actual_fd(&buffer, fd);
	if (!actual)
		return (ft_free_all(&buffer, actual, NULL, NULL), free(d), NULL);
	if (!(ft_gnl_read(actual, &d, ft_memchar(actual->vec->buf, '\n',
					actual->vec->index))))
		return (ft_free_all(&buffer, actual, NULL, NULL), free(d), NULL);
	if (actual->end)
		ft_free_all(&buffer, actual, NULL, NULL);
	return (d);
}

/**
 * @brief	Reads from the file descriptor into the buffer until a newline is
 * 			found or EOF is reached.
 * 
 * @param	actual The buffer structure for the current file descriptor.
 * @param	d A pointer to store the resulting line.
 * @param	idx_nl The index of the newline character in the buffer.
 * @return	A pointer to the read line, or NULL on failure.
 */
char	*ft_gnl_read(t_buffer *actual, char **d, ssize_t idx_nl)
{
	int		readed;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	readed = read(actual->fd, buf, BUFFER_SIZE);
	if (readed < 0)
		return (free(buf), NULL);
	while (readed > 0)
	{
		if (!ft_add_char_vector(buf, actual->vec, readed))
			return (free(buf), NULL);
		idx_nl = ft_memchar(actual->vec->buf, '\n', actual->vec->index);
		if (idx_nl != -1)
			break ;
		readed = read(actual->fd, buf, BUFFER_SIZE);
	}
	if (readed == 0 && idx_nl < 0)
		actual->end = true;
	free(buf);
	if (idx_nl != -1)
		return (ft_gnl_dest(d, actual->vec->buf, idx_nl, actual));
	else
		return (ft_gnl_dest(d, actual->vec->buf, actual->vec->index, actual));
}

/**
 * @brief	Extracts a line from the buffer and adjusts the buffer accordingly.
 * 
 * @param	d A pointer to store the resulting line.
 * @param	buf The buffer containing the line.
 * @param	idx The index of the line in the buffer.
 * @param	actual The buffer structure for the current file descriptor.
 * @return	A pointer to the extracted line, or NULL on failure.
 */
char	*ft_gnl_dest(char **d, char *buf, ssize_t idx, t_buffer *actual)
{
	if ((size_t)idx != actual->vec->index)
	{
		d[0] = (char *)malloc(sizeof(char) * (idx + 2));
		if (!(d[0]))
			return (NULL);
		ft_memcpy(d[0], buf, idx + 1);
		d[0][idx + 1] = 0;
		ft_memcpy(buf, &buf[idx + 1], (actual->vec->index - (idx + 1)));
		actual->vec->index = actual->vec->index - (idx + 1);
		return (d[0]);
	}
	else if (actual->vec->index > 0)
	{
		d[0] = (char *)malloc(sizeof(char) * (idx + 1));
		if (!(d[0]))
			return (NULL);
		ft_memcpy(d[0], buf, idx);
		d[0][idx] = 0;
		actual->vec->index = 0;
		return (d[0]);
	}
	return (NULL);
}

/**
 * @brief	Finds or creates a buffer structure for the given file descriptor.
 * 
 * @param	start A pointer to the start of the buffer linked list.
 * @param	fd The file descriptor to find or create a buffer for.
 * @return	A pointer to the buffer structure for the given file descriptor.
 */
t_buffer	*ft_actual_fd(t_buffer **start, int fd)
{
	t_buffer	*tmp;

	tmp = *start;
	if (tmp->fd == fd)
		return (tmp);
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->fd == fd)
			return (tmp);
	}
	tmp->next = ft_new_struct(fd);
	return (tmp->next);
}

/**
 * @brief	Creates a new buffer structure for the given file descriptor.
 * 
 * @param	fd The file descriptor to create a buffer for.
 * @return	A pointer to the newly created buffer structure, or NULL on failure.
 */
t_buffer	*ft_new_struct(int fd)
{
	t_buffer	*new;

	new = (t_buffer *)malloc(sizeof(t_buffer) * 1);
	if (!new)
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	new->vec = ft_new_vector();
	if (!new->vec)
		return (free(new), NULL);
	new->end = false;
	return (new);
}
