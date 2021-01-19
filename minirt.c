/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 12:52:11 by mwinter           #+#    #+#             */
/*   Updated: 2021/01/05 19:59:49 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_all(t_all *all, int argc)
{
	all->res.parsed = 0;
	all->camera_c = 0;
	all->light_c = 0;
	if (argc == 2)
		all->bmp = 0;
	else
		all->bmp = 1;
}

int			main(int argc, char **argv)
{
	t_all		*all;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
		handle_error("fail malloc at start", all);
	if (argc == 1 || argc > 3 || (argc == 3 && !ft_strcmp(argv[2], "--save")))
		handle_error("wrong arguments.", all);
	if (!ft_extension(argv[1]))
		handle_error("wrong file extension.", all);
	if ((all->fd = open(argv[1], O_RDONLY)) < 0)
		handle_error("scene file is broken", all);
	init_all(all, argc);
	parse_scene(all);
	start_rt(all);
	if (argc == 3)
		make_bmp(create_file(all, argv[1]), all);
	if (!all->bmp)
	{
		mlx_key_hook(all->mlx_win, key_hook, all);
		mlx_hook(all->mlx_win, 17, 0L, ft_close, &all);
		mlx_loop(all->mlx);
	}
	return (1);
}
