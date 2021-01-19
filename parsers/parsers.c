/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:06:40 by mwinter           #+#    #+#             */
/*   Updated: 2021/01/06 21:12:20 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	parse_type(t_all *all)
{
	if (ft_strcmp(all->scene[0], "R"))
		parse_resolution(all);
	else if (ft_strcmp(all->scene[0], "A"))
		parse_ambient(all);
	else if (ft_strcmp(all->scene[0], "c"))
		parse_camera(all);
	else if (ft_strcmp(all->scene[0], "l"))
		parse_light(all);
	else if (ft_strcmp(all->scene[0], "pl"))
		parse_plane(all);
	else if (ft_strcmp(all->scene[0], "sp"))
		parse_sphere(all);
	else if (ft_strcmp(all->scene[0], "sq"))
		parse_square(all);
	else if (ft_strcmp(all->scene[0], "cy"))
		parse_cylinder(all);
	else if (ft_strcmp(all->scene[0], "tr"))
		parse_triangle(all);
}

void	parse_scene(t_all *all)
{
	int i;

	i = 1;
	while (i)
	{
		i = get_next_line(all->fd, &all->line);
		all->scene = ft_setsplit(all->line, " \t\v\n\r\f");
		parse_type(all);
		ft_free_split(all->scene);
		free(all->line);
	}
	close(all->fd);
	if (!all->res.parsed)
		handle_error("no resolution.\n", all);
	if (all->camera_c == 0)
		handle_error("no cameras.\n", all);
	make_full_ring(&all->cam_lst);
}
