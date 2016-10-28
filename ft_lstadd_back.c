/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 21:31:38 by rromero           #+#    #+#             */
/*   Updated: 2016/10/23 21:31:39 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*node;

	if (!new || !alst)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		node = *alst;
		while (node->next)
			node = node->next;
		node->next = new;
	}
}
