#include "checker.h"

void            push_head(t_alist *list1, t_alist *list2)
{
	t_elem  *tmp;

	tmp = list2->head;
	if (list2->len > 1)
	{
		list2->head->next->prev = NULL;
		list2->head = list2->head->next;
	}
	tmp->prev = NULL;
	tmp->next = NULL;
	if (list1->head == NULL)
		list1->head = tmp;
	else
	{
		list1->head->prev = tmp;
		tmp->next = list1->head;
		tmp->prev = NULL;
		list1->head = tmp;
	}
	if (list1->tail == NULL)
		list1->tail = tmp;
	list2->len--;
	list1->len++;
	if (list2->len == 0)
	{
		list2->head = NULL;
		list2->tail = NULL;
	}
}

void            ft_push_front(t_alist *list, int value)
{
	t_elem  *node;

	node = (t_elem *)malloc(sizeof(t_elem));
	if (node == NULL)
		exit(ERROR);
	node->val = value;
	node->next = NULL;
	node->prev = list->tail;
	if (list->tail)
		list->tail->next = node;
	list->tail = node;
	if (list->head == NULL)
		list->head = node;
	list->len++;
}

void            printList(t_alist *list)
{
	t_elem  *tmp;

	tmp = list->head;
	while (tmp)
	{
		ft_putnbr(tmp->val);
		write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}