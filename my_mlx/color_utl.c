/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:44:26 by mwinter           #+#    #+#             */
/*   Updated: 2020/12/31 18:21:35 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_color		multiple_rgb(t_color c, double i)
{
	if (i > 1)
		return (c);
	return ((t_color){c.r * i, c.g * i, c.b * i});
}

int			multiple_lght(t_color color, double i)
{
	return (create_rgb(color.r * i, color.g * i, color.b * i));
}

int			create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

t_color		add_color(t_color c1, t_color c2, double i)
{
	if (i > 1)
	{
		return ((t_color){c1.r += c2.r / 255, c1.g += c2.g / 255,
				c1.b += c2.b / 255});
	}
	return ((t_color){c1.r += (c2.r / 255) * i, c1.g += (c2.g / 255) * i,
			c1.b += (c2.b / 255) * i});
}

t_color		check_color(t_color clr)
{
	clr.r = clr.r > 255 ? 255 : clr.r;
	clr.g = clr.g > 255 ? 255 : clr.g;
	clr.b = clr.b > 255 ? 255 : clr.b;
	return (clr);
}
