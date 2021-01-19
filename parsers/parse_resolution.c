/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:18:18 by mwinter           #+#    #+#             */
/*   Updated: 2021/01/06 21:12:46 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	parse_resolution(t_all *all)
{
	int x;
	int y;

	if (all->res.parsed)
		handle_error("need one resolution", all);
	if (arg_count(all->scene) != 3 || !check_parse(all->scene))
		handle_error("invalid resolution.", all);
	all->res.crd.x = ft_atof(all->scene[1]);
	all->res.crd.y = ft_atof(all->scene[2]);
	mlx_get_screen_size(all->mlx, &x, &y);
	all->res.crd.x = all->res.crd.x > x ? x : all->res.crd.x;
	all->res.crd.y = all->res.crd.y > y ? y : all->res.crd.y;
	if (all->res.crd.x < 1 || all->res.crd.y < 1)
		handle_error("very small resolution.", all);
	all->res.parsed = 1;
}
