/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:54:40 by mwinter           #+#    #+#             */
/*   Updated: 2020/12/01 16:19:06 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	parse_light(t_all *all)
{
	t_lght	*light;

	if (!(light = (t_lght *)malloc(sizeof(t_lght))))
		handle_error("fail to malloc in light parse", all);
	if (arg_count(all->scene) != 4 || !check_parse(all->scene))
		handle_error("invalid light.", all);
	light->pol = split_vector(all->scene[1], all, 0);
	light->brght = ft_atof(all->scene[2]);
	if (light->brght < 0 || light->brght > 1)
		handle_error("invalid light brightness", all);
	light->color = split_color(all->scene[3], all);
	ft_lstadd_back(&all->lght_lst, ft_lstnew(light));
}
