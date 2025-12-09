/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:52:07 by benpicar          #+#    #+#             */
/*   Updated: 2025/12/09 13:06:22 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include "get_next_line.h"

inline bool	print_res(char *key, char *value)
{
	(void)key;
	write(1, CYAN, 7);
	write(1, value, ft_strlen(value));
	write(1, "\n", 1);
	write(1, NC, 4);
	return (true);
}

inline void	print_not_found(char *key)
{
	write(1, YELLOW, 7);
	write(1, key, ft_strlen(key));
	write(1, ": Not found.\n", 13);
	write(1, NC, 4);
}

inline void	print_error(t_hash_table **table, char *msg)
{
	write(1, RED, 7);
	write(1, msg, ft_strlen(msg));
	write(1, NC, 4);
	free_hash_table(table);
}
