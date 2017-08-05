/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:05:42 by rromero           #+#    #+#             */
/*   Updated: 2017/03/23 09:09:45 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // snode_new, <s_push>, <s_pop>, <s_look> & <snode_del>

t_stckn		*snode_new(void const *data, size_t d_size)
{
	t_stckn	*new;

	new = ft_memalloc(sizeof(t_stckn));
	if (!new || !data)
		return (0);
	new->d_size = d_size;
	if (d_size && data)
	{
		new->data = ft_memalloc(d_size);
		if (!new->data)
		{
			ft_memdel((void **)new);
			return (0);
		}
		new->data = ft_memcpy(new->data, data, d_size);
	}
	return (new);
}

t_stckn		*stack_push(t_stckn *top, t_stckn *new)
{
	if (!new || !top)
		return (0);
	new->next = top;
	return (new);
}

t_stckn		*stack_pop(t_stckn *top)
{
	if (!top)
		return (0);
	return (top->next);
}

t_stckn		*stack_lookup(t_stckn *top, t_stckn *node)
{
	if (!top || !node)
		return (0);
	while ((top->next) && top != node)
		top = top->next;
	return (top == node ? node : 0);
}

void		snode_del(t_stckn *node)
{
	if (node)
	{
		node->d_size = 0;
		if (node->data)
			ft_memdel(&node->data);
		ft_memdel((void **)&node);
	}
}
