/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:35:36 by mwinter           #+#    #+#             */
/*   Updated: 2020/11/29 19:45:38 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	char		*d;
	const char	*s;
	size_t		n;

	if (!dst)
		return (0);
	d = dst;
	s = src;
	n = dsize;
	if (n)
	{
		while (--n)
		{
			if ((*d++ = *s++) == '\0')
				break ;
		}
	}
	if (n == 0)
	{
		if (dsize != 0)
			*d = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}
