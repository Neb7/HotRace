/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:44:11 by benpicar          #+#    #+#             */
/*   Updated: 2025/12/09 12:44:10 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include "get_next_line.h"

inline void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		while (n >= sizeof(long long))
		{
			((long long *)s)[i] = 0;
			i++;
			n = n - sizeof(long long);
		}
		i = i * sizeof(long long);
		while (n > 0)
		{
			((unsigned char *)s)[i] = 0;
			n--;
			i++;
		}
	}
}

inline char	*ft_strdup_no_nl(char *s)
{
	char	*d;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\n')
		len--;
	d = (char *)malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	ft_memcpy(d, s, len);
	d[len] = '\0';
	return (d);
}

inline size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

inline int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
