/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:52:07 by benpicar          #+#    #+#             */
/*   Updated: 2025/12/08 18:17:58 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include "get_next_line.h"

bool	print_res(char *key, char *value)
{
	write(1, key, ft_strlen(key));
	write(1, ": ", 2);
	write(1, value, ft_strlen(value));
	write(1, "\n", 1);
	return (true);
}

void	print_not_found(char *key)
{
	write(1, key, ft_strlen(key));
	write(1, ": Not found.\n", 13);
}
