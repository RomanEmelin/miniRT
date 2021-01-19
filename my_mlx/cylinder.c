/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 14:14:41 by mwinter           #+#    #+#             */
/*   Updated: 2020/12/31 16:50:47 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_crd			get_cy_normal(t_figure cy, t_crd p)
{
	t_crd	pc;
	t_crd	n;
	double	h;

	pc = make_vect(p, cy.crd1, '-');
	h = dot(pc, cy.orient);
	n = make_vect(pc, multiple_vect(cy.orient, h), '-');
	return (normalize(n));
}

static t_crd	quadratic_cylinder(t_crd d, t_figure cy, t_crd oc)
{
	t_crd	t;
	t_crd	h;
	t_crd	oc_h;
	t_crd	abc;
	double	dscr;

	h = multiple_vect(cy.orient, dot(d, cy.orient));
	h = make_vect(d, h, '-');
	oc_h = multiple_vect(cy.orient, dot(oc, cy.orient));
	oc_h = make_vect(oc, oc_h, '-');
	abc.x = dot(h, h);
	abc.y = 2 * dot(h, oc_h);
	abc.z = dot(oc_h, oc_h) - pow(cy.dmtr / 2, 2);
	dscr = pow(abc.y, 2) - 4 * abc.x * abc.z;
	if (dscr < 0)
		return ((t_crd){INFINITY, INFINITY, 0});
	if (dscr == 0)
		return ((t_crd){-abc.y / (2 * abc.x), -abc.y / (2 * abc.x), 0});
	t.x = (-abc.y + sqrt(dscr)) / (2 * abc.x);
	t.y = (-abc.y - sqrt(dscr)) / (2 * abc.x);
	return (t);
}

double			intersect_cylinder(t_crd o, t_crd d, t_figure cy)
{
	t_crd	t;
	t_crd	p[2];
	double	h[2];
	double	res;
	t_crd	oc;

	oc = make_vect(o, cy.crd1, '-');
	t = quadratic_cylinder(d, cy, oc);
	if (t.x == INFINITY && t.y == INFINITY)
		return (INFINITY);
	p[0] = make_vect(o, multiple_vect(d, t.x), '+');
	h[0] = dot(cy.orient, make_vect(p[0], cy.crd1, '-'));
	p[1] = make_vect(o, multiple_vect(d, t.y), '+');
	h[1] = dot(cy.orient, make_vect(p[1], cy.crd1, '-'));
	if (-cy.sd_size / 2 <= h[0] && h[0] <= cy.sd_size / 2 && t.x > 0.001)
		res = t.x;
	if (-cy.sd_size / 2 <= h[1] && h[1] <= cy.sd_size / 2 && t.y > 0.001)
		res = t.y;
	return (res);
}
