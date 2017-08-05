/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkdlst2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:51:36 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 01:51:37 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_slln	*ft_lstmap(t_slln *lst, t_slln *(*f)(t_slln *elem))
{
	t_slln	*node;

	if (!lst || !f)
		return (0);
	if (lst->next)
	{
		node = ft_lstmap(lst->next, f);
		ft_lstadd(&node, f(lst));
	}
	else
		node = f(lst);
	return (node);
}

void	ft_lstadd_back(t_slln **alst, t_slln *new)
{
	t_slln	*node;

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

size_t	ft_lstlen(t_slln *head)
{
	size_t	count;

	count = 0;
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}

void				destroy_dlst(t_slln *lst)
{
	(void)lst;
	return ;
}
