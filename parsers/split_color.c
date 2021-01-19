/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:14:28 by mwinter           #+#    #+#             */
/*   Updated: 2021/01/01 17:37:10 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static int	check_color_split(char **s)
{
	if (!ft_strlen(s[0]) || !ft_strlen(s[1]) || !ft_strlen(s[2]))
		return (0);
	else if (ft_strlen(s[0]) > 3 || ft_strlen(s[1]) > 3 || ft_strlen(s[2]) > 3)
		return (0);
	return (1);
}

t_color		split_color(char *s, t_all *all)
{
	char	**color;
	t_color clr;

	if (c_count(s, ',') != 2)
		handle_error("invalid color.", all);
	color = ft_setsplit(s, ",");
	if (arg_count(color) != 3 || !check_color_split(color))
		handle_error("invalid color.", all);
	clr.r = ft_atoi(color[0]);
	clr.g = ft_atoi(color[1]);
	clr.b = ft_atoi(color[2]);
	ft_free_split(color);
	if (clr.r > 255 || clr.g > 255 ||
		clr.b > 255 || clr.r < 0 ||
		clr.g < 0 || clr.b < 0)
		handle_error("invalid color range.", all);
	return (clr);
}
