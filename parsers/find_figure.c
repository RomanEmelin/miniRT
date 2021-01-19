/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:34:40 by mwinter           #+#    #+#             */
/*   Updated: 2020/12/31 16:16:28 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_figure	*find_figure(t_all *all, int id)
{
	t_list		*tmp;
	t_figure	*fg;

	tmp = all->figure_lst;
	while (tmp)
	{
		fg = (t_figure *)tmp->content;
		if (fg->id == id)
			return (fg);
		tmp = tmp->next;
	}
	return (fg);
}
