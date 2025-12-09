/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:12:04 by benpicar          #+#    #+#             */
/*   Updated: 2025/12/09 11:10:42 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include "get_next_line.h"

static inline bool	fill_hash_table(t_hash_table **table)
{
	char	*line;
	char	*key;
	size_t	count;

	line = get_next_line(0);
	count = 0;
	while (line && line[0] != '\n')
	{
		if (count % 2 == 0)
			key = line;
		else
		{
			if (!hash_insert(table, key, line))
				return (free(line), free(key), false);
			free(key);
			free(line);
		}
		count++;
		line = get_next_line(0);
	}
	if (count % 2 != 0)
	{
		if (!hash_insert(table, key, ""))
			return (free(key), free(line), false);
		free(key);
	}
	free(line);
	return (true);
}

static inline void	process_searches(t_hash_table *table)
{
	char	*line;
	char	*key;
	char	*clean_line;

	line = get_next_line(0);
	while (line)
	{
		clean_line = ft_strdup_no_nl(line);
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
}

int	main(void)
{
	t_hash_table	*table;

	table = create_hash_table();
	if (!table)
		return (1);
	if (!fill_hash_table(&table))
		return (-1);
	process_searches(table);
	free_hash_table(&table);
	return (0);
}
