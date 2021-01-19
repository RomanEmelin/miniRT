/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 14:45:40 by mwinter           #+#    #+#             */
/*   Updated: 2020/12/31 16:51:24 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_crd	get_sp_normal(t_figure sp, t_crd p)
{
	return (normalize(make_vect(p, sp.crd1, '-')));
}

double	intersect_sphere(t_crd o, t_crd d, t_figure sp)
{
	t_crd	oc;
	t_crd	crd;
	t_crd	abc;
	double	discriminant;

	oc = make_vect(o, sp.crd1, '-');
	abc.x = dot(d, d);
	abc.y = 2 * dot(oc, d);
	abc.z = dot(oc, oc) - pow(sp.dmtr / 2, 2);
	discriminant = pow(abc.y, 2) - 4 * abc.x * abc.z;
	if (discriminant < 0)
		return (INFINITY);
	else if (discriminant == 0)
		return (-abc.y / (2 * abc.x));
	crd.x = (-abc.y + sqrt(discriminant)) / (2 * abc.x);
	crd.y = (-abc.y - sqrt(discriminant)) / (2 * abc.x);
	return (crd.x > crd.y ? crd.y : crd.x);
}
