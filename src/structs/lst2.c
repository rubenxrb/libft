#include "libft.h"

t_dlln	*dllst_findstr(t_list *list, const char *str, t_byte head)
{
	t_dlln	*tmp;

	if (!list || !list->len || !str)
		return (0);
	tmp = head ? list->head : list->tail;
	while (tmp)
	{
		if (!ft_strncmp(tmp->data, str, ft_strlen(str)))
			return (tmp);
		tmp = head ? tmp->next : tmp->prev;
	}
	return (0);
}

void	dllst_delstr(t_list *list, const char *str, t_byte head)
{
	t_dlln	*del;

	if (!list || !list->len || !str)
		return ;
	del = dllst_findstr(list, str, head);
	if (!del)
		return ;
	if (del->prev)
		del->prev->next = del->next;
	if (del->next)
		del->next->prev = del->prev;
	dlnode_free(&del);
}

void	dllst_print(t_list *list, t_byte head)
{
	t_dlln	*tmp;

	if (!list || !list->len)
		return ;
	tmp = head ? list->head : list->tail;
	while (tmp)
	{
		ft_putendl(tmp->data);
		tmp = head ? tmp->next : tmp->prev;
	}
}

void	dllst_del(t_list *list)
{
	t_dlln	*head;

	if (!list)
		return ;
	head = list->head;
	if (head)
		dlinklst_free(&head);
	list->head = 0;
	list->tail = 0;
	list->len = 0;
}
