/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:17:34 by benpicar          #+#    #+#             */
/*   Updated: 2025/12/16 17:13:06 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/**
 * @brief	Create a new vector
 * 
 * @param	nb_octect The size of each element in the vector
 */
t_vector	*ft_new_vector(size_t nb_octect)
{
	t_vector	*new;

	new = (t_vector *)ft_calloc(1, sizeof(t_vector));
	if (!new)
		return ((t_vector *) NULL);
	new->buf = (void *)ft_calloc(2, nb_octect);
	if (!(new->buf))
		return (free(new), (t_vector *) NULL);
	new->index = 0;
	new->max_len = 2;
	new->nb_octect = nb_octect;
	return (new);
}

/**
 * @brief	Add a data to the vector, if the vector is full, it will be resized
 * 
 * @param	s The data to add
 * @param	vector The vector to add the data to
 * @param	len The number of elements to add
 * @return	t_vector* The vector with the new data, or NULL if an error occured
 */
t_vector	*ft_add_char_vector(void *s, t_vector *vector, size_t len)
{
	void	*dbl;

	if (vector->index + len <= vector->max_len)
	{
		ft_memcpy(vector->buf + (vector->index * vector->nb_octect), s,
			len * vector->nb_octect);
		vector->index = vector->index + len;
	}
	else
	{
		dbl = (void *)ft_calloc(vector->nb_octect,
				((vector->max_len * 2) + len));
		if (!(dbl))
			return ((t_vector *) NULL);
		ft_memcpy(dbl, vector->buf, vector->index * vector->nb_octect);
		vector->max_len = (vector->max_len * 2) + len;
		free(vector->buf);
		vector->buf = (void *)dbl;
		ft_memcpy(vector->buf + (vector->index * vector->nb_octect), s,
			len * vector->nb_octect);
		vector->index = vector->index + len;
	}
	return (vector);
}

/**
 * @brief	Free the memory allocated for the vector
 * 
 * @param	vector The vector to free
 */
void	ft_free_vector(t_vector **vector)
{
	free((*vector)->buf);
	free(*vector);
	*vector = NULL;
}

/**
 * @brief	Convert the vector to a string
 * 
 * @param	vector The vector to convert
 */
char	*ft_vtos(t_vector *vector)
{
	char	*d;

	d = (char *)malloc(sizeof(char) * (vector->index + 1));
	if (!d)
		return (NULL);
	ft_memcpy(d, vector->buf, vector->index);
	d[vector->index] = 0;
	return (d);
}

inline void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
