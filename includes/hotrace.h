/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:11:28 by benpicar          #+#    #+#             */
/*   Updated: 2025/12/08 16:33:39 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

# define HASH_TABLE_SIZE 4096

# define CYAN	"\033[0;96m"
# define RED	"\033[0;91m"
# define YELLOW	"\033[0;93m"
# define NC		"\033[0m"

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

/* hash.c */
size_t			hash_function(const char *key);
t_hash_table	*create_hash_table(void);
bool			hash_insert(t_hash_table **table, char *key, char *value);
char			*hash_search(t_hash_table *table, char *key);

/* utils.c */
void			ft_bzero(void *s, size_t n);
char			*ft_strdup_no_nl(char *s);
size_t			ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);

/* print.c */
bool			print_res(char *key, char *value);
void			print_not_found(char *key);
void			print_error(t_hash_table **table, char *msg);

/* free.c */
void			free_hash_table(t_hash_table **table);

#endif
