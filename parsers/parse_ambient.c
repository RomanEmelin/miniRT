/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:06:33 by mwinter           #+#    #+#             */
/*   Updated: 2020/12/01 16:18:07 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	parse_ambient(t_all *all)
{
	if (all->light_c)
		handle_error("invalid ambient light", all);
	if (arg_count(all->scene) != 3 || !check_parse(all->scene))
		handle_error("invalid ambient ligth.", all);
	all->amb.ratio = ft_atof(all->scene[1]);
	if (1 < all->amb.ratio || all->amb.ratio < 0)
		handle_error("invalid ambient light.", all);
	all->amb.color = split_color(all->scene[2], all);
	all->light_c++;
}
