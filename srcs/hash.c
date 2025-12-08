/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:42:02 by benpicar          #+#    #+#             */
/*   Updated: 2025/12/08 18:22:57 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include "get_next_line.h"

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

t_hash_table	*create_hash_table(void)
{
	t_hash_table	*table;

	table = (t_hash_table *)malloc(sizeof(t_hash_table));
	if (!table)
		return (NULL);
	// ft_bzero(table, sizeof(t_hash_table));
	table->size = HASH_TABLE_SIZE;
	table->array = (t_dict **)malloc(sizeof(t_dict *) * table->size);
	if (!table->array)
	{
		free(table);
		return (NULL);
	}
	ft_bzero(table->array, sizeof(t_dict *) * table->size);
	return (table);
}

bool	hash_insert(t_hash_table **table, char *key, char *value)
{
	size_t	index;
	t_dict	*new_dict;

	new_dict = (t_dict *)malloc(sizeof(t_dict));
	if (!new_dict)
		return (false);
	new_dict->key = ft_strdup_no_nl(key);
	new_dict->value = ft_strdup_no_nl(value);
	if (!new_dict->key || !new_dict->value)
	{
		free(new_dict->key);
		free(new_dict->value);
		free(new_dict);
		return (false);
	}
	index = hash_function(new_dict->key);
	new_dict->next = (*table)->array[index];
	(*table)->array[index] = new_dict;
	return (true);
}

char	*hash_search(t_hash_table *table, char *key)
{
	size_t	index;
	t_dict	*current;
	char	*clean_key;
	char	*result;

	clean_key = ft_strdup_no_nl(key);
	if (!clean_key)
		return (NULL);
	index = hash_function(clean_key);
	current = table->array[index];
	result = NULL;
	while (current)
	{
		if (ft_strcmp(current->key, clean_key) == 0)
		{
			result = current->value;
			break;
		}
		current = current->next;
	}
	free(clean_key);
	return (result);
}
