/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 10:45:01 by mwinter           #+#    #+#             */
/*   Updated: 2020/11/30 10:59:01 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	const char *s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

static char		*free_join(char **s1, char **s2)
{
	free(*s1);
	free(*s2);
	return (NULL);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	if (!(res = (char *)malloc((ft_strlen(s1)
		+ ft_strlen(s2) + 1) * sizeof(char))))
		return (free_join((char **)&s1, (char **)&s2));
	i = 0;
	while ((res[i] = s1[i]) && s1[i])
		i++;
	j = 0;
	while ((res[i] = s2[j]) && s2[j])
	{
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char			*ft_strdup(const char *s)
{
	char		*res;
	size_t		size;
	char		*tmp;

	if (!s)
		return (NULL);
	size = ft_strlen(s) + 1;
	if (!(res = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	tmp = res;
	while (size--)
		*tmp++ = *s++;
	return (res);
}
