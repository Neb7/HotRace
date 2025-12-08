/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:44:12 by benpicar          #+#    #+#             */
/*   Updated: 2025/08/31 14:53:50 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief	Allocates and initializes a new t_vector structure.
 *
 * @return	Pointer to the newly allocated t_vector structure,
 * 			or NULL if memory allocation fails.
 */
t_vector	*ft_new_vector(void)
{
	t_vector	*new;

	new = (t_vector *)malloc(sizeof(t_vector));
	if (!new)
		return ((t_vector *) NULL);
	new->buf = (char *)malloc(sizeof(char) * 2);
	if (!(new->buf))
		return (free(new), (t_vector *) NULL);
	new->index = 0;
	new->max_len = 2;
	new->buf[0] = 0;
	new->buf[1] = 0;
	return (new);
}

/**
 * @brief	Appends a string to the t_vector buffer, resizing if necessary.
 * 
 * @param	s The string to append.
 * @param	vector The t_vector structure to append to.
 * @param	len The length of the string to append.
 * @return	A pointer to the updated t_vector structure, or NULL on failure.
 */
t_vector	*ft_add_char_vector(char *s, t_vector *vector, size_t len)
{
	char	*dbl;

	if (vector->index + len <= vector->max_len)
	{
		ft_memcpy(&vector->buf[vector->index], s, len);
		vector->index = vector->index + len;
	}
	else
	{
		dbl = (char *)malloc(sizeof(char) * ((vector->max_len * 2) + len));
		if (!(dbl))
			return ((t_vector *) NULL);
		ft_memcpy(dbl, vector->buf, vector->max_len);
		vector->max_len = (vector->max_len * 2) + len;
		free(vector->buf);
		vector->buf = dbl;
		ft_memcpy(&vector->buf[vector->index], s, len);
		vector->index = vector->index + len;
	}
	return (vector);
}

/**
 * @brief	Frees a buffer structure and its associated resources.
 * 
 * @param	start A pointer to the start of the buffer linked list.
 * @param	tmp The buffer structure to free.
 * @param	tmp2 A temporary pointer used in the freeing process.
 * @param	tmp3 A temporary pointer used in the freeing process.
 */
void	ft_free_all(t_buffer **start, t_buffer *tmp, t_buffer *tmp2, \
t_buffer *tmp3)
{
	bool		check;

	check = false;
	tmp3 = *start;
	if (tmp3 == tmp)
		check = true;
	else
		while (tmp3->next != tmp)
			tmp3 = tmp3->next;
	if (tmp != NULL)
	{
		tmp2 = tmp->next;
		free(tmp->vec->buf);
		free(tmp->vec);
		free(tmp);
	}
	tmp = *start;
	if (check)
		*start = tmp2;
	else
	{
		tmp3->next = tmp2;
	}
}

/**
 * @brief	Copies memory from source to destination.
 * 
 * @param	dest The destination memory area.
 * @param	src The source memory area.
 * @param	n The number of bytes to copy.
 * @return	A pointer to the destination memory area.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest != NULL && src != NULL)
	{
		while (n >= sizeof(long long))
		{
			((long long *)dest)[i] = ((long long *)src)[i];
			i++;
			n = n - sizeof(long long);
		}
		i = i * sizeof(long long);
		while (n > 0)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			n--;
			i++;
		}
	}
	return (dest);
}

/**
 * @brief	Searches for a character in a memory area.
 * 
 * @param	s The memory area to search.
 * @param	c The character to search for.
 * @param	n The number of bytes to search.
 * @return	The index of the character if found, or -1 if not found.
 */
ssize_t	ft_memchar(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr = (const unsigned char *)s;

	i = 0;
	if (s != NULL)
	{
		while (i < n)
		{
			if (ptr[i] == (unsigned char)c)
				return (i);
			i++;
		}
	}
	return (-1);
}
