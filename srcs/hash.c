/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:42:02 by benpicar          #+#    #+#             */
/*   Updated: 2025/12/08 16:42:14 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

size_t	hash_function(const char *key)
{
	size_t	hash;
	size_t	i;

	hash = 5381;
	i = 0;
	while (key[i])
	{
		hash = ((hash << 5) + hash) + (unsigned char)key[i];
		i++;
	}
	return (hash % HASH_TABLE_SIZE);
}
