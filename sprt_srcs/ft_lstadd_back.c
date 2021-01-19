/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:08:20 by mwinter           #+#    #+#             */
/*   Updated: 2021/01/05 21:34:54 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last_elem;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_elem = ft_lstlast(*lst);
	last_elem->next = new;
}
