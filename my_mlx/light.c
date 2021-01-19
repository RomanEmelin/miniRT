/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:40:32 by mwinter           #+#    #+#             */
/*   Updated: 2020/12/31 18:03:11 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static void	calc_diff_light(double c[4], t_lght l, t_color *res, t_crd vec[2])
{
	c[0] += l.brght * c[2] / (vect_len(vec[0]) * vect_len(vec[1]));
	*res = add_color(*res, l.color, c[0]);
}

static void	calc_specular_light(double c[4], t_color *res, t_lght l, t_crd v[4])
{
	if (SPECULAR > 0)
	{
		v[3] = make_vect(multiple_vect(v[0], 2 * dot(v[0], v[2])), v[2], '-');
		c[3] = dot(v[3], v[1]);
		if (c[3] > 0)
		{
			c[1] += l.brght *
				pow(c[3] / (vect_len(v[3]) * vect_len(v[1])), SPECULAR);
			*res = add_color(*res, l.color, c[1]);
		}
	}
}

t_color		manage_light(t_crd p, t_crd n, t_crd v, t_all *all)
{
	double		coef[4];
	t_color		cur_lght;
	t_list		*tmp;
	t_lght		lght;
	t_crd		lr[2];

	coef[0] = 0;
	coef[1] = 0;
	tmp = all->lght_lst;
	cur_lght = add_color((t_color){0, 0, 0}, all->amb.color, all->amb.ratio);
	while (tmp)
	{
		lght = *(t_lght *)tmp->content;
		lr[0] = make_vect(lght.pol, p, '-');
		coef[2] = dot(n, normalize(lr[0]));
		if (!closest_t(p, lr[0], (double[2]){0.00001, 0.9}, all) && coef[2] > 0)
		{
			calc_diff_light(coef, lght, &cur_lght, (t_crd[2]){n, lr[0]});
			calc_specular_light(coef, &cur_lght, lght,
					(t_crd[4]){n, v, lr[0], lr[1]});
		}
		tmp = tmp->next;
	}
	return (cur_lght);
}
