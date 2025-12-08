/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:12:04 by benpicar          #+#    #+#             */
/*   Updated: 2025/12/08 18:31:37 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include "get_next_line.h"

// static inline	fill_hash_table(t_hash_table **table)
// {
	
// }

int	main(void)
{
	t_hash_table	*table;
	char			*line;
	char			*key;
	size_t			count;
	
	table = create_hash_table();
	if (!table)
		return (1);
	line = get_next_line(0);
	count = 0;
	while (line && line[0] != '\n')
	{
		if (count % 2 == 0)
		{
			key = line;
		}
		else
		{
			hash_insert(&table, key, line);
			free(key);
			free(line);
		}
		count++;
		line = get_next_line(0);
	}
	if (count % 2 != 0)
	{
		hash_insert(&table, key, "");
		free(key);
	}
	free(line);
	line = get_next_line(0);
	while (line)
	{
		char *clean_line = ft_strdup_no_nl(line);
		if (clean_line)
		{
			key = hash_search(table, clean_line);
			if (key)
				print_res(clean_line, key);
			else
				print_not_found(clean_line);
			free(clean_line);
		}
		free(line);
		line = get_next_line(0);
	}
	free_hash_table(&table);
	return (0);
}
