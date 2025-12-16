/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 00:00:00 by benpicar          #+#    #+#             */
/*   Updated: 2025/12/16 17:13:06 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <fcntl.h>

#define BUFFER_SIZE 1048576  // 1MB buffer pour lecture rapide

static inline char	*extract_line(t_fast_buffer *buf)
{
	size_t	start;
	size_t	len;
	char	*line;

	if (buf->pos >= buf->size)
		return (NULL);
	start = buf->pos;
	len = 0;
	while (buf->pos < buf->size && buf->data[buf->pos] != '\n')
	{
		buf->pos++;
		len++;
	}
	if (buf->pos < buf->size)
		buf->pos++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, buf->data + start, len);
	line[len] = '\0';
	return (line);
}

inline bool	read_all_stdin(t_fast_buffer *buf)
{
	ssize_t	bytes_read;
	size_t	total_read;
	size_t	capacity;

	capacity = BUFFER_SIZE;
	buf->data = malloc(capacity);
	if (!buf->data)
		return (false);
	total_read = 0;
	while (1)
	{
		bytes_read = read(0, buf->data + total_read, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		total_read += bytes_read;
		if (total_read + BUFFER_SIZE > capacity)
		{
			buf->data = extend_buffer(buf->data, total_read, &capacity);
			if (!buf->data)
				return (false);
		}
	}
	buf->size = total_read;
	buf->pos = 0;
	return (true);
}

inline bool	fast_fill_hash_table(t_hash_table **table, t_fast_buffer *buf)
{
	char	*line;
	char	*key;
	size_t	count;

	if (!read_all_stdin(buf))
		return (false);
	key = NULL;
	count = 0;
	while (1)
	{
		line = extract_line(buf);
		if (!line || line[0] == '\0')
		{
			free(line);
			break ;
		}
		process_key_value(table, &key, line, &count);
	}
	if (count % 2 != 0)
	{
		hash_insert(table, key, "");
		free(key);
	}
	return (true);
}

static inline void	process_search_line(t_hash_table *table, t_vector *out,
		char *line)
{
	char	*result;

	if (line[0] == '\0')
		return ;
	result = hash_search(table, line);
	if (result)
		append_result(out, line, result);
	else
		append_not_found(out, line);
}

inline void	fast_process_searches(t_hash_table *table, t_fast_buffer *buf)
{
	char		*line;
	t_vector	*output;

	output = ft_new_vector(1);
	if (!output)
		return ;
	while (1)
	{
		line = extract_line(buf);
		if (!line)
			break ;
		process_search_line(table, output, line);
		free(line);
	}
	write(1, output->buf, output->index);
	ft_free_vector(&output);
	free(buf->data);
}
