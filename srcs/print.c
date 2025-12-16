/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:52:07 by benpicar          #+#    #+#             */
/*   Updated: 2025/12/16 17:01:47 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

inline void	print_error(t_hash_table **table, char *msg)
{
	write(2, msg, ft_strlen(msg));
	free_hash_table(table);
}
