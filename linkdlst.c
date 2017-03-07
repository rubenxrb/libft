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

#include "libft.h"	// lstnew, lstdelone, lstdel, lstadd & lstiter

t_node		*ft_lstnew(void const *data, size_t data_size)
{
	t_node *head;

	head = (t_node *)malloc(sizeof(t_node));
	if (!head)
		return (0);
	if (!data)
	{
		head->data = 0;
		head->d_size = 0;
	}
	else
	{
		head->data = malloc(data_size);
		if (!head->data)
		{
			free(head);
			return (0);
		}
		ft_memcpy(head->data, data, data_size);
		head->d_size = data_size;
	}
	head->next = 0;
	return (head);
}

void	ft_lstdelone(t_node **curr, void (*del)(void *, size_t))
{
	if (*curr)
	{
		del((*curr)->data, (*curr)->d_size);
		ft_memdel((void **)curr);
	}
}

void	ft_lstdel(t_node **alst, void (*del)(void *, size_t))
{
	if (*alst && del)
	{
		ft_lstdel(&(*alst)->next, del);
		ft_lstdelone(alst, del);
	}
}

void	ft_lstadd(t_node **alst, t_node *new)
{
	if (!alst || !new)
		return ;
	if (*alst)
		new->next = *alst;
	*alst = new;
}

void	ft_lstiter(t_node *lst, void (*f)(t_node *node))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
