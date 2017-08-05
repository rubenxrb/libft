
#include "libft.h"

t_dlln	*split_dlinklst(t_dlln **starting)
{
	t_dlln	*fast;
	t_dlln	*slow;
	t_dlln	*tmp;

	fast = *starting;
	slow = *starting;
	while ((fast->next) && (fast->next->next))
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	tmp = slow->next;
	slow->next = 0;
	return (tmp);
}

t_dlln	*dlinklst_merge(t_dlln *lst, t_dlln *tmp, t_byte (*cmp)(void *, void *))
{
	if (!lst)
		return (tmp);
	if (!tmp)
		return (lst);
	if (cmp(lst->data, tmp->data) > 0)
	{
		lst->next = dlinklst_merge(lst->next, tmp, cmp);
		lst->next->prev = lst;
		lst->prev = 0;
		return (lst);
	}
	else
	{
		tmp->next = dlinklst_merge(lst, tmp->next, cmp);
		tmp->next->prev = tmp;
		tmp->prev = 0;
		return (tmp);
	}
}


t_dlln	*dlinklst_sort(t_dlln **head, t_byte (*cmp)(void *, void *))
{
	t_dlln	*tmp;

	if (!*head || !(*head)->next)
		return (*head);
	tmp = split_dlinklst(head);
	*head = dlinklst_sort(head, cmp);
	tmp  = dlinklst_sort(&tmp, cmp);
	return (dlinklst_merge(*head, tmp, cmp));
}
