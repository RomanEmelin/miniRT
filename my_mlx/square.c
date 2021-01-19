/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 14:48:30 by mwinter           #+#    #+#             */
/*   Updated: 2020/12/31 16:46:08 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	intersect_square(t_crd o, t_crd d, t_figure sq)
{
	double	t;
	t_crd	p;
	t_crd	dst;

	if ((t = intersect_plane(o, d, sq)) == INFINITY)
		return (INFINITY);
	p = make_vect(o, multiple_vect(d, t), '+');
	dst = make_vect(p, sq.crd1, '-');
	if (fabs(dst.x) > sq.sd_size / 2 || fabs(dst.y) > sq.sd_size / 2 ||
		fabs(dst.z) > sq.sd_size / 2)
		return (INFINITY);
	return (t);
}
