/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:23:20 by mwinter           #+#    #+#             */
/*   Updated: 2021/01/06 21:12:36 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	parse_plane(t_all *all)
{
	t_figure *pl;

	if (!(pl = (t_figure *)malloc(sizeof(t_figure))))
		handle_error("fail malloc in plane parse", all);
	if (arg_count(all->scene) != 4 || !check_parse(all->scene))
		handle_error("invalid plane arguments.", all);
	pl->crd1 = split_vector(all->scene[1], all, 0);
	pl->orient = normalize(split_vector(all->scene[2], all, 1));
	pl->color = split_color(all->scene[3], all);
	pl->specular = SPECULAR;
	pl->t = INFINITY;
	pl->id = 1;
	ft_lstadd_back(&all->figure_lst, ft_lstnew(pl));
}

void	parse_sphere(t_all *all)
{
	t_figure *sp;

	if (!(sp = (t_figure *)malloc(sizeof(t_figure))))
		handle_error("fail malloc in sphere parse", all);
	if (arg_count(all->scene) != 4 || !check_parse(all->scene))
		handle_error("invalid sphere arguments.", all);
	sp->crd1 = split_vector(all->scene[1], all, 0);
	if ((sp->dmtr = ft_atof(all->scene[2])) <= 0)
		handle_error("invalid sp diametr.", all);
	sp->color = split_color(all->scene[3], all);
	sp->specular = SPECULAR;
	sp->t = INFINITY;
	sp->id = 2;
	ft_lstadd_back(&all->figure_lst, ft_lstnew(sp));
}

void	parse_square(t_all *all)
{
	t_figure *sq;

	if (!(sq = (t_figure *)malloc(sizeof(t_figure))))
		handle_error("fail malloc in square parse", all);
	if (arg_count(all->scene) != 5 || !check_parse(all->scene))
		handle_error("invalid square arguments.", all);
	sq->crd1 = split_vector(all->scene[1], all, 0);
	sq->orient = normalize(split_vector(all->scene[2], all, 1));
	if ((sq->sd_size = ft_atof(all->scene[3])) <= 0)
		handle_error("invalid square side size.", all);
	sq->color = split_color(all->scene[4], all);
	sq->specular = SPECULAR;
	sq->t = INFINITY;
	sq->id = 3;
	ft_lstadd_back(&all->figure_lst, ft_lstnew(sq));
}

void	parse_cylinder(t_all *all)
{
	t_figure *cy;

	if (!(cy = (t_figure *)malloc(sizeof(t_figure))))
		handle_error("fail malloc in cylinder parse", all);
	if (arg_count(all->scene) != 6 || !check_parse(all->scene))
		handle_error("invalid cylinder arguments.", all);
	cy->crd1 = split_vector(all->scene[1], all, 0);
	cy->orient = normalize(split_vector(all->scene[2], all, 1));
	cy->dmtr = ft_atof(all->scene[3]);
	if ((cy->sd_size = ft_atof(all->scene[4])) <= 0)
		handle_error("invalid cylinder height.", all);
	cy->crd1.x *= cy->sd_size / 2;
	cy->crd1.y *= cy->sd_size / 2;
	cy->color = split_color(all->scene[5], all);
	cy->specular = SPECULAR;
	cy->t = INFINITY;
	cy->id = 4;
	ft_lstadd_back(&all->figure_lst, ft_lstnew(cy));
}

void	parse_triangle(t_all *all)
{
	t_figure *tr;

	if (!(tr = (t_figure *)malloc(sizeof(t_figure))))
		handle_error("fail malloc in triangle parse", all);
	if (arg_count(all->scene) != 5 || !check_parse(all->scene))
		handle_error("invalid triangle arguments.", all);
	tr->crd1 = split_vector(all->scene[1], all, 0);
	tr->crd2 = split_vector(all->scene[2], all, 0);
	tr->crd3 = split_vector(all->scene[3], all, 0);
	tr->color = split_color(all->scene[4], all);
	tr->orient = get_tr_normal(*tr);
	tr->specular = SPECULAR;
	tr->t = INFINITY;
	tr->id = 5;
	check_triangle(tr->crd1, tr->crd2, tr->crd3, all);
	ft_lstadd_back(&all->figure_lst, ft_lstnew(tr));
}
