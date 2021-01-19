/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_orient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:38:16 by mwinter           #+#    #+#             */
/*   Updated: 2020/12/31 16:18:31 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_crd	split_vector(char *s, t_all *all, int flag)
{
	t_crd	crd;
	char	**vector;

	vector = ft_setsplit(s, ",");
	if (arg_count(vector) != 3 || c_count(s, ',') != 2)
		handle_error("invalid  orient vector.", all);
	crd.x = ft_atof(vector[0]);
	crd.y = ft_atof(vector[1]);
	crd.z = ft_atof(vector[2]);
	ft_free_split(vector);
	if (flag && (crd.x > 1 || crd.y > 1 || crd.z > 1 || crd.x < -1 || crd.y < -1
		|| crd.z < -1))
		handle_error("invalid orient vector.", all);
	if (flag && crd.x == 0 && crd.y == 0 && crd.z == 0)
		handle_error("invalid orient vector.", all);
	return (crd);
}
