#include "checker.h"

void 	ra(t_alist *list)
{
	t_elem	*tmp;

	if (list->len > 1)
	{
		tmp = list->head;
		list->head = tmp->next;
		tmp->prev = list->tail;
		tmp->next = NULL;
		list->tail->next = tmp;
		list->tail = tmp;
	}
}

void 	rb(t_alist *list)
{
	t_elem	*tmp;

	if (list->len > 1)
	{
		tmp = list->head;
		list->head = tmp->next;
		tmp->prev = list->tail;
		tmp->next = NULL;
		list->tail->next = tmp;
		list->tail = tmp;
	}
}

void 	rr(t_alist *list_a, t_alist *list_b)
{
	ra(list_a);
	rb(list_b);
}