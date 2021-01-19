/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:40:53 by mwinter           #+#    #+#             */
/*   Updated: 2021/01/05 20:54:41 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_figure	*closest_t(t_crd o, t_crd d, double t[2], t_all *all)
{
	t_figure	*fg;
	t_figure	*closest_fg;
	t_list		*tmp;
	double		t_fg;
	double		closest_t;

	closest_fg = NULL;
	closest_t = INFINITY;
	tmp = all->figure_lst;
	while (tmp)
	{
		fg = tmp->content;
		t_fg = choose_fg(o, d, fg);
		if (t[0] < t_fg && t_fg < t[1] && t_fg < closest_t)
		{
			closest_fg = fg;
			closest_fg->t = t_fg;
			closest_t = t_fg;
		}
		tmp = tmp->next;
	}
	return (closest_fg);
}

int			trace_ray(t_all *all, t_crd dir)
{
	t_figure	*fg;
	t_color		clr;
	t_crd		p;
	t_crd		n;

	if (!(fg = closest_t(all->cam->pov, dir, (double[2]){1, INFINITY}, all)))
		return (multiple_lght(all->amb.color, all->amb.ratio));
	p = make_vect(all->cam->pov, multiple_vect(dir, fg->t), '+');
	n = get_normal(*fg, p);
	if (dot(n, dir) > 0)
		n = multiple_vect(n, -1);
	clr = manage_light(p, n, multiple_vect(dir, -1), all);
	clr = (t_color){fg->color.r * clr.r, fg->color.g * clr.g,
					fg->color.b * clr.b};
	clr = check_color(clr);
	return (create_rgb(clr.r, clr.g, clr.b));
}

static void	render_x(t_all *all, t_crd pixel, double angle)
{
	int		color;
	t_crd	dir;
	t_crd	scale;

	pixel.x = 0;
	while (pixel.x < all->res.crd.x)
	{
		scale.x = (pixel.x - all->res.crd.x / 2) * angle;
		scale.y = (all->res.crd.y / 2 - pixel.y - 1) * angle;
		dir = make_cam(canvas_to_viewport(scale, all), all->cam->orient);
		dir = normalize(dir);
		color = trace_ray(all, dir);
		my_pixel_put(all, pixel.x, pixel.y, color);
		pixel.x++;
	}
}

void		render(t_all *all)
{
	t_crd	pixel;
	double	angle;

	all->img.img = mlx_new_image(all->mlx, all->res.crd.x, all->res.crd.y);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
		&all->img.line_length, &all->img.endian);
	all->cam = all->cam_lst->content;
	angle = tan(all->cam->fov * M_PI / 360);
	pixel.y = 0;
	while (pixel.y < all->res.crd.y)
	{
		render_x(all, pixel, angle);
		pixel.y++;
	}
	if (!all->bmp)
		mlx_put_image_to_window(all->mlx, all->mlx_win, all->img.img, 0, 0);
	write(1, "Image ready\n", 12);
}

void		start_rt(t_all *all)
{
	if (!all->light_c)
		handle_error("have no source of light", all);
	if (!(all->mlx = mlx_init()))
		handle_error("fail to MinilibX init.", all);
	if (!(all->mlx_win = mlx_new_window(all->mlx, all->res.crd.x,
		all->res.crd.y, "rT")))
		handle_error("fail to create window", all);
	render(all);
}
