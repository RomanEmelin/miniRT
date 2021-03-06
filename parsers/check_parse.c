/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:40:03 by mwinter           #+#    #+#             */
/*   Updated: 2020/12/31 16:17:19 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	check_parse(char **s)
{
	int i;
	int j;

	i = 1;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (!ft_isdigit(s[i][j]) && s[i][j] != '.' && s[i][j] != ',' &&
					s[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
