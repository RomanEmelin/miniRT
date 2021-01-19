/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 18:15:34 by mwinter           #+#    #+#             */
/*   Updated: 2021/01/01 17:36:27 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char *)s;
	while (n--)
	{
		*tmp = 0;
		tmp++;
	}
}

int		ft_close(void **all)
{
	t_all **new;

	new = (t_all **)all;
	mlx_clear_window((*new)->mlx, (*new)->mlx_win);
	mlx_destroy_window((*new)->mlx, (*new)->mlx_win);
	exit(1);
}

double	choose_fg(t_crd o, t_crd d, t_figure *fg)
{
	double t;

	fg->id == 1 ? t = intersect_plane(o, d, *fg) : 0;
	fg->id == 2 ? t = intersect_sphere(o, d, *fg) : 0;
	fg->id == 3 ? t = intersect_square(o, d, *fg) : 0;
	fg->id == 4 ? t = intersect_cylinder(o, d, *fg) : 0;
	fg->id == 5 ? t = intersect_triangle(o, d, *fg) : 0;
	return (t);
}

t_crd	canvas_to_viewport(t_crd scale, t_all *all)
{
	t_crd crd;

	if (all->res.crd.x < all->res.crd.y)
	{
		crd.x = scale.x * 1 / all->res.crd.x;
		crd.y = scale.y * (1 / all->res.crd.y) *
				all->res.crd.y / all->res.crd.x;
	}
	else if (all->res.crd.x > all->res.crd.y)
	{
		crd.x = scale.x * (1 / all->res.crd.x) *
				all->res.crd.x / all->res.crd.y;
		crd.y = scale.y * 1 / all->res.crd.y;
	}
	else
	{
		crd.x = scale.x * 1 / all->res.crd.x;
		crd.y = scale.y * 1 / all->res.crd.x;
	}
	crd.z = 1;
	return (crd);
}
