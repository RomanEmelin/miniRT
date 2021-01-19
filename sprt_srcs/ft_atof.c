/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 12:52:11 by mwinter           #+#    #+#             */
/*   Updated: 2020/12/31 16:04:00 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	double	ans;
	int		len;
	int		flag;

	flag = *str == '-' ? 1 : 0;
	res = ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	res2 = ft_atoi(str);
	len = ft_strlen(str);
	while (len--)
		res2 /= 10;
	ans = res + ((res < 0) ? -res2 : res2);
	if (!res && flag)
		ans *= -1;
	return (ans);
}
