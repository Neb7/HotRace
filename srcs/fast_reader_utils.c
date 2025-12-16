/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_reader_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 00:00:00 by benpicar          #+#    #+#             */
/*   Updated: 2025/12/16 17:13:06 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

inline void	append_result(t_vector *output, char *line, char *result)
{
	ft_add_char_vector(line, output, ft_strlen(line));
	ft_add_char_vector(": ", output, 2);
	ft_add_char_vector(result, output, ft_strlen(result));
	ft_add_char_vector("\n", output, 1);
}

inline void	append_not_found(t_vector *output, char *line)
{
	ft_add_char_vector(line, output, ft_strlen(line));
	ft_add_char_vector(": Not found.\n", output, 13);
}

inline void	process_key_value(t_hash_table **table, char **key,
		char *line, size_t *count)
{
	if (*count % 2 == 0)
		*key = line;
	else
	{
		hash_insert(table, *key, line);
		free(*key);
		free(line);
	}
	(*count)++;
}

inline char	*extend_buffer(char *data, size_t total_read, size_t *capacity)
{
	char	*new_data;

	*capacity *= 2;
	new_data = malloc(*capacity);
	if (!new_data)
		return (NULL);
	ft_memcpy(new_data, data, total_read);
	free(data);
	return (new_data);
}
