/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:11:28 by benpicar          #+#    #+#             */
/*   Updated: 2025/12/16 17:14:10 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

# define HASH_TABLE_SIZE 524288

typedef struct s_vector
{
	void	*buf;
	size_t	index;
	size_t	max_len;
	size_t	nb_octect;
}	t_vector;

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
extern t_hash_table	*create_hash_table(void);
extern bool			hash_insert(t_hash_table **table, char *key, char *value);
extern char			*hash_search(t_hash_table *table, char *key);

/* utils.c */
extern void			ft_bzero(void *s, size_t n);
extern char			*ft_strdup_no_nl(char *s);
extern size_t		ft_strlen(const char *s);
extern int			ft_strcmp(const char *s1, const char *s2);
extern void			*ft_memcpy(void *dest, const void *src, size_t n);

/* print.c */
extern void			print_error(t_hash_table **table, char *msg);

/* free.c */
extern void			free_hash_table(t_hash_table **table);

/* fast_reader.c */
typedef struct s_fast_buffer
{
	char	*data;
	size_t	size;
	size_t	pos;
}	t_fast_buffer;

extern bool			read_all_stdin(t_fast_buffer *buf);
extern bool			fast_fill_hash_table(t_hash_table **table,
						t_fast_buffer *buf);
extern void			fast_process_searches(t_hash_table *table,
						t_fast_buffer *buf);

/* fast_reader_utils.c */
extern void			append_result(t_vector *output, char *line, char *result);
extern void			append_not_found(t_vector *output, char *line);
extern void			process_key_value(t_hash_table **table, char **key,
						char *line, size_t *count);
extern char			*extend_buffer(char *data, size_t total_read,
						size_t *capacity);

/* ft_vector.c */
extern t_vector		*ft_new_vector(size_t nb_octect);
extern t_vector		*ft_add_char_vector(void *s, t_vector *vector, size_t len);
extern void			ft_free_vector(t_vector **vector);
extern char			*ft_vtos(t_vector *vector);
extern void			*ft_calloc(size_t nmemb, size_t size);

#endif
