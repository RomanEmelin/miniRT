/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 14:42:19 by mwinter           #+#    #+#             */
/*   Updated: 2020/12/31 17:00:16 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double		intersect_triangle(t_crd o, t_crd d, t_figure tr)
{
	t_crd	e[2];
	t_crd	ptq[3];
	double	det;
	double	inv_det;
	double	uv[2];

	e[0] = make_vect(tr.crd2, tr.crd1, '-');
	e[1] = make_vect(tr.crd3, tr.crd1, '-');
	ptq[0] = cross_vec(d, e[1]);
	det = dot(e[0], ptq[0]);
	if (fabs(det) < 0.00001)
		return (INFINITY);
	inv_det = 1 / det;
	ptq[1] = make_vect(o, tr.crd1, '-');
	uv[0] = dot(ptq[1], ptq[0]) * inv_det;
	if (uv[0] < 0 || uv[0] > 1)
		return (INFINITY);
	ptq[2] = cross_vec(ptq[1], e[0]);
	uv[1] = dot(d, ptq[2]) * inv_det;
	if (uv[1] < 0 || uv[0] + uv[1] > 1)
		return (INFINITY);
	return (dot(e[1], ptq[2]) * inv_det);
}

t_crd		get_tr_normal(t_figure tr)
{
	t_crd v1;
	t_crd v2;

	v1 = make_vect(tr.crd2, tr.crd1, '-');
	v2 = make_vect(tr.crd3, tr.crd1, '-');
	return (normalize(cross_vec(v1, v2)));
}
