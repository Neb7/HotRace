/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:11:03 by benpicar          #+#    #+#             */
/*   Updated: 2025/12/09 12:37:24 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "hotrace.h"

inline void	free_hash_table(t_hash_table **table)
{
	size_t	i;
	t_dict	*current;
	t_dict	*tmp;

	if (!table || !(*table))
		return ;
	i = 0;
	while (i < (*table)->size)
	{
		current = (*table)->array[i];
		while (current)
		{
			tmp = current;
			current = current->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
		i++;
	}
	free((*table)->array);
	free(*table);
	*table = NULL;
}
