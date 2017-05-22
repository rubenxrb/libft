#include "libft.h"

void	dllst_delstr(t_lst *list, const char *str, t_byte head)
{
	t_dlnode	*del;

	if (!list || !list->len || !str)
		return ;
	del = dllst_findstr(list, str, head);
	if (!del)
		return ;
	if (del->prev)
		del->prev->next = del->next;
	if (del->next)
		del->next->prev = del->prev;
	dlnode_del(&del, ft_bzero);
}

t_dlnode	*dllst_findstr(t_lst *list, const char *str, t_byte head)
{
	t_dlnode	*tmp;

	if (!list || !list->len || !str)
		return (0);
	tmp = head ? list->head : list->tail;
	while (tmp)
	{
		if (!ft_strcmp(tmp->data, str))
			return (tmp);
		tmp = head ? tmp->next : tmp->prev;
	}
	return (0);
}

void	dllst_print(t_lst *list, t_byte head)
{
	t_dlnode	*tmp;

	if (!list || !list->len)
		return ;
	tmp = head ? list->head : list->tail;
	while (tmp)
	{
		ft_putendl(tmp->data);
		tmp = head ? tmp->next : tmp->prev;
	}
}
