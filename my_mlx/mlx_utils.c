/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 18:11:45 by mwinter           #+#    #+#             */
/*   Updated: 2021/01/05 20:54:08 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void		my_pixel_put(t_all *all, int x, int y, int color)
{
	char *dst;

	dst = all->img.addr + (y * all->img.line_length + x *
			(all->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	change_cam(t_all *all, int flag)
{
	if (flag)
	{
		mlx_clear_window(all->mlx, all->mlx_win);
		all->cam_lst = all->cam_lst->next;
		render(all);
	}
	else
	{
		mlx_clear_window(all->mlx, all->mlx_win);
		all->cam_lst = all->cam_lst->prev;
		render(all);
	}
}

int			key_hook(int keycode, t_all *all)
{
	if (keycode == 53)
	{
		mlx_clear_window(all->mlx, all->mlx_win);
		mlx_destroy_window(all->mlx, all->mlx_win);
		exit(1);
	}
	else if (keycode == 1)
		render(all);
	else if (keycode == 124 && all->camera_c > 1)
		change_cam(all, 1);
	else if (keycode == 123 && all->camera_c > 1)
		change_cam(all, 0);
	else if (keycode == 125)
	{
		mlx_clear_window(all->mlx, all->mlx_win);
		all->cam->fov = all->cam->fov + 5 > 180 ? 180 : all->cam->fov + 5;
		render(all);
	}
	else if (keycode == 126)
	{
		mlx_clear_window(all->mlx, all->mlx_win);
		all->cam->fov = all->cam->fov - 5 < 0 ? 1 : all->cam->fov - 5;
		render(all);
	}
	return (keycode);
}
