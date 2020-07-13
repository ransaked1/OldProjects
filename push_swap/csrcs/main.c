/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:53:48 by dbraghis          #+#    #+#             */
/*   Updated: 2017/03/18 16:08:10 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void 			del_list(t_alist *list)
{
	t_elem	*tmp;

	while (list->head)
	{
		tmp = list->head;
		list->head = list->head->next;
		free(tmp);
	}
}

t_alist     *create(void)
{
	t_alist *tmp;

	tmp = (t_alist *)malloc(sizeof(t_alist));
	tmp->len = 0;
	tmp->head = NULL;
	tmp->tail = NULL;
	return (tmp);
}

void	ft_exit(t_stacks *stacks, int error)
{
	if (error == ERROR && stacks->stack_a != NULL && stacks->stack_b != NULL)
	{
		del_list(stacks->stack_a);
		del_list(stacks->stack_b);
		//free(stacks);
	}
	if (error == EXCEPTION)
		exit(0);
	ft_putstr("Error\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_stacks	stacks;
	t_alist		*list_a;
	t_alist		*list_b;

	list_a = create();
	list_b = create();
	ft_bzero(&stacks, sizeof(stacks));
	if (argc >= 2)
	{
		stacks.stack_a = list_a;
		stacks.stack_b = list_b;
		stacks.count = argc - 1;
		check_arg(&stacks, &argv[1]);
		read_op(list_a, list_b);
	}
	else
	{
		ft_exit(&stacks, EXCEPTION);
		write(1, "\n", 1);
	}
	del_list(list_a);
	//free(&stacks);
	return (0);
}
