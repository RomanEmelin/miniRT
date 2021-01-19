/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:33:35 by mwinter           #+#    #+#             */
/*   Updated: 2020/12/31 19:05:53 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	free_all(t_all *all)
{
	(void)all;
}

void	handle_error(char *s, t_all *all)
{
	write(2, "Error: ", 7);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	free_all(all);
	exit(1);
}
