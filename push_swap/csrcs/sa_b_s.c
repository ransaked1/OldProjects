#include "checker.h"

void    sa(t_alist *list_a)
{
	long int tmp;

	if (list_a->len > 1)
	{
		tmp = list_a->head->val;
		list_a->head->val = list_a->head->next->val;
		list_a->head->next->val = tmp;
	}
}

void    sb(t_alist *list_b)
{
	long int tmp;

	if (list_b->len > 1)
	{
		tmp = list_b->head->val;
		list_b->head->val = list_b->head->next->val;
		list_b->head->next->val = tmp;
	}
}

void    ss(t_alist *list_a, t_alist *list_b)
{
	sa(list_a);
	sb(list_b);
}