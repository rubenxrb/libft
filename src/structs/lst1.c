/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 02:09:07 by rromero           #+#    #+#             */
/*   Updated: 2017/03/24 18:43:20 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_addstr(t_list *list, const char *str)
{
	t_slln		*add;

	if (!str)
		return ;
	if (!list->head)
	{
		list->head = ft_lstnew(str, ft_strlen(str) + 1);
		list->tail = list->head;
	}
	else
	{
		add = ft_lstnew(str, ft_strlen(str) + 1);
		((t_slln *)(list->tail))->next = add;
		list->tail = add;
	}
	list->len++;
}

void	lst_addnewarray(t_list *list, const char *name)
{
	t_array		string;
	t_slln		*add;

	if (!name)
		return ;
	string.array = ft_strdup(name);
	string.d_size = 1;
	string.len = ft_strlen(name);
	string.bytes = (string.len + 1);
	if (!list->head)
	{
		list->head = ft_lstnew(&string, sizeof(t_array));
		list->tail = list->head;
	}
	else
	{
		add = ft_lstnew(&string, sizeof(t_array));
		((t_slln *)(list->tail))->next = add;
		list->tail = add;
	}
	list->len++;
}

void	lst_addwstr(t_list *list, const wchar_t *name)
{
	t_array		string;
	t_slln		*add;

	if (!name || !list)
		return ;
	string.array = wstrdup(name);
	string.d_size = sizeof(wchar_t);
	string.len = wstrlen(name);
	string.bytes = ((string.d_size * string.len) + sizeof(wchar_t));
	if (!list->head)
	{
		list->head = ft_lstnew(&string, sizeof(t_array));
		list->tail = list->head;
	}
	else
	{
		add = ft_lstnew(&string, sizeof(t_array));
		((t_slln *)(list->tail))->next = add;
		list->tail = add;
	}
	list->len++;
}

void	lst_addarray(t_list *list, t_array *add)
{
	t_slln	*new;

	if (!add || !list)
		return ;
	new = ft_memalloc(sizeof(t_slln));
	if (!new)
		return ;
	new->data = add;
	if (!list->head)
	{
		list->head = new;
		list->tail = list->head;
	}
	else
	{
		((t_slln *)(list->tail))->next = new;
		list->tail = new;
	}
	list->len++;
}

void	dllst_addstr(t_list *lst, const char *str)
{
	t_dlln	*add;
	t_dlln	*tmp;

	if (!str)
		return ;
	if (!lst->head)
	{
		lst->head = dlnode_new(str, ft_strlen(str) + 1);
		lst->tail = lst->head;
	}
	else
	{
		tmp = lst->tail;
		add = dlnode_new(str, ft_strlen(str) + 1);
		dlnode_addnext(tmp, add);
		lst->tail = add;
	}
	lst->len++;
}
