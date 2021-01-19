/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 14:37:36 by mwinter           #+#    #+#             */
/*   Updated: 2020/12/31 16:14:17 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	dot(t_crd v1, t_crd v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double	vect_len(t_crd v)
{
	return (sqrt(dot(v, v)));
}

t_crd	multiple_vect(t_crd v, double i)
{
	return ((t_crd){v.x * i, v.y * i, v.z * i});
}

t_crd	normalize(t_crd v)
{
	double len;

	len = vect_len(v);
	return ((t_crd){v.x / len, v.y / len, v.z / len});
}

t_crd	make_vect(t_crd v1, t_crd v2, int flag)
{
	if (flag == '+')
		return ((t_crd){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
	if (flag == '-')
		return ((t_crd){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
	return ((t_crd){v1.x * v2.x, v1.y * v2.y, v1.z * v2.z});
}
