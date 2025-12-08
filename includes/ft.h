/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:11:28 by benpicar          #+#    #+#             */
/*   Updated: 2025/12/08 16:33:39 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h> 

# define HASH_TABLE_SIZE 4096

typedef struct s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
}	t_dict;

typedef struct s_hash_table
{
	t_dict	**array;
	size_t	size;
}	t_hash_table;

#endif
