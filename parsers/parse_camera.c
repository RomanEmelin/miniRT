/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:15:05 by mwinter           #+#    #+#             */
/*   Updated: 2020/12/31 16:19:13 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	list_init(t_list **lst, t_list *new)
{
	t_list *last_elem;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_elem = ft_lstlast(*lst);
	last_elem->next = new;
	new->prev = last_elem;
}

void	make_full_ring(t_list **cam_lst)
{
	t_list *end;

	end = *cam_lst;
	while (end->next)
	{
		end = end->next;
	}
	(*cam_lst)->prev = end;
	end->next = *cam_lst;
}

void	parse_camera(t_all *all)
{
	t_cam	*cam;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		handle_error("fail to malloc i camera parse", all);
	if (arg_count(all->scene) != 4 || !check_parse(all->scene))
		handle_error("invalid camera.", all);
	cam->pov = split_vector(all->scene[1], all, 0);
	cam->orient = normalize((split_vector(all->scene[2], all, 1)));
	cam->fov = ft_atoi(all->scene[3]);
	if (cam->fov < 1 || cam->fov > 180)
		handle_error("invalid camera fov", all);
	list_init(&all->cam_lst, ft_lstnew(cam));
	all->camera_c++;
}
