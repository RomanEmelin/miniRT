/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:04:14 by mwinter           #+#    #+#             */
/*   Updated: 2021/01/05 21:35:28 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

size_t			ft_wordcount(char const *s)
{
	size_t res;

	res = 0;
	while (*s)
	{
		if (!ft_isspace(*s))
			res++;
		while (!ft_isspace(*s) && *(s + 1))
			s++;
		s++;
	}
	return (res);
}

static size_t	ft_strlen_sp(char const *s)
{
	size_t len;

	len = 0;
	while (!ft_isspace(*s) && *s)
	{
		s++;
		len++;
	}
	return (len);
}

static void		*ft_free(char **res, size_t i)
{
	while (i)
	{
		free(res[i]);
		res[i] = NULL;
	}
	free(res);
	res = NULL;
	return (res);
}

char			**ft_split(char const *s)
{
	char	**res;
	size_t	i;
	size_t	k;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	if (!(res = (char **)malloc((ft_wordcount(s) + 1) * sizeof(char *))))
		return (NULL);
	while (i < ft_wordcount(s))
	{
		if (!(res[i] = (char *)malloc((ft_strlen_sp(&s[k]) + 1)
			* sizeof(char))))
			ft_free(res, i);
		while (ft_isspace(s[k]))
			k++;
		ft_strlcpy(res[i], &s[k], ft_strlen_sp(&s[k]) + 1);
		while (!ft_isspace(s[k]) && s[k])
			k++;
		i++;
	}
	res[i] = NULL;
	return (res);
}
