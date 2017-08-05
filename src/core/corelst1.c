/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkdlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:45:10 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 01:45:11 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_slln	*ft_lstnew(void const *data, size_t data_size)
{
	t_slln *head;

	head = ft_memalloc(sizeof(t_slln));
	if (!head)
		return (0);
	if (!data)
	{
		head->data = 0;
		head->d_size = 0;
	}
	else
	{
		head->data = ft_memalloc(data_size);
		if (!head->data)
		{
			ft_memdel((void **)head);
			return (0);
		}
		head->data = ft_memcpy(head->data, data, data_size);
		head->d_size = data_size;
	}
	head->next = 0;
	return (head);
}

void	ft_lstdelone(t_slln **curr, void (*bzero)(void *, size_t))
{
	if (*curr)
	{
		bzero((*curr)->data, (*curr)->d_size);
		ft_memdel((void **)curr);
	}
}

void	ft_lstdel(t_slln **alst, void (*bzero)(void *, size_t))
{
	if (*alst && bzero)
	{
		ft_lstdel(&(*alst)->next, bzero);
		ft_lstdelone(alst, bzero);
	}
}

void	ft_lstadd(t_slln **alst, t_slln *new)
{
	if (!alst || !new)
		return ;
	if (*alst)
		new->next = *alst;
	*alst = new;
}

void	ft_lstiter(t_slln *lst, void (*f)(t_slln *node))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
