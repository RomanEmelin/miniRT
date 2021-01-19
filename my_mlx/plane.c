/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 14:39:45 by mwinter           #+#    #+#             */
/*   Updated: 2020/12/31 16:42:35 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	intersect_plane(t_crd o, t_crd d, t_figure pl)
{
	double o_pl;
	double d_or;

	o_pl = dot(make_vect(o, pl.crd1, '-'), pl.orient);
	d_or = dot(d, pl.orient);
	if (d_or == 0 || (o_pl < 0 && d_or < 0) || (o_pl > 0 && d_or > 0))
		return (INFINITY);
	return (-o_pl / d_or < 0 ? INFINITY : -o_pl / d_or);
}
