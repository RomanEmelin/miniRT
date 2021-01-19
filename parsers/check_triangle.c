/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 18:11:09 by mwinter           #+#    #+#             */
/*   Updated: 2021/01/05 20:53:30 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	check_triangle(t_crd c1, t_crd c2, t_crd c3, t_all *all)
{
	if (c1.x == c2.x && c1.y == c2.y && c1.z == c2.z)
		handle_error("invalid triangle coordinates.", all);
	if (c1.x == c3.x && c1.y == c3.y && c1.z == c3.z)
		handle_error("invalid triangle coordinates.", all);
	if (c3.x == c2.x && c3.y == c2.y && c3.z == c2.z)
		handle_error("invalid triangle coordinates.", all);
}
