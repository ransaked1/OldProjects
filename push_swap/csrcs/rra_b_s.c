#include "checker.h"

void 	rra(t_alist *list)
{
	t_elem	*tmp;

	if (list->len > 1)
	{
		tmp = list->tail;
		list->tail = list->tail->prev;
		if (list->len > 1)
			list->tail->next = NULL;
		tmp->next = list->head;
		tmp->prev = NULL;
		list->head->prev = tmp;
		list->head = tmp;
	}
}

void 	rrb(t_alist *list)
{
	t_elem	*tmp;

	if (list->len > 1)
	{
		tmp = list->tail;
		list->tail = list->tail->prev;
		if (list->len > 1)
			list->tail->next = NULL;
		tmp->next = list->head;
		tmp->prev = NULL;
		list->head->prev = tmp;
		list->head = tmp;
	}
}

void 	rrr(t_alist *list_a, t_alist *list_b)
{
	rra(list_a);
	rrb(list_b);
}
