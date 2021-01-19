/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 14:51:10 by mwinter           #+#    #+#             */
/*   Updated: 2020/12/31 19:06:37 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_crd	cross_vec(t_crd a, t_crd b)
{
	return ((t_crd){a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
					a.x * b.y - a.y * b.x});
}

t_crd	get_normal(t_figure fg, t_crd p)
{
	if (fg.id == 1 || fg.id == 3 || fg.id == 5)
		return (fg.orient);
	else if (fg.id == 2)
		return (get_sp_normal(fg, p));
	else
		return (get_cy_normal(fg, p));
}

t_crd	make_cam(t_crd d, t_crd orient)
{
	t_crd	mx;
	t_crd	my;
	t_crd	mz;

	orient.x *= -1;
	orient.y *= -1;
	mz = orient;
	mx = cross_vec((t_crd){0, 1, 0}, mz);
	my = cross_vec(mz, mx);
	return ((t_crd){d.x * mx.x + d.y * mx.y + d.z * mx.z,
					d.x * my.x + d.y * my.y + d.z * my.z,
					d.x * mz.x + d.y * mz.y + d.z * mz.z});
}
