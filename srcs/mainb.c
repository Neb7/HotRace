/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:12:04 by benpicar          #+#    #+#             */
/*   Updated: 2025/12/16 16:36:11 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	main(void)
{
	t_hash_table	*table;
	t_fast_buffer	buf;

	table = create_hash_table();
	if (!table)
		return (1);
	if (!fast_fill_hash_table(&table, &buf))
		return (free_hash_table(&table), -1);
	fast_process_searches(table, &buf);
	free_hash_table(&table);
	return (0);
}
