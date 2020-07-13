#include "checker.h"

void	pa(t_alist *list_a, t_alist *list_b)
{
	if (list_b->len == 0)
		return ;
	push_head(list_a, list_b);
}

void	pb(t_alist *list_a, t_alist *list_b)
{
	if (list_a->len == 0)
		return ;
	push_head(list_b, list_a);
}