/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:42:39 by eproust           #+#    #+#             */
/*   Updated: 2024/11/13 19:26:36 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*i;
	t_list	*j;
	int		tmp;

	i = lst;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (!cmp(i->data, j->data))
			{
				tmp = i->data;
				i->data = j->data;
				j->data = tmp;	
			}
			j = j->next;
		}
		i = i->next;
	}	
	return (lst);
}

/*
int ascending(int a, int b)
{
	return (a <= b);
}

int	descending(int a, int b)
{
	return (a >= b);
}

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list *list;

	t_list	node3 = {9, NULL};
	t_list	node2 = {1, &node3};
	t_list	node1 = {3, &node2};

	list = sort_list(&node1, descending);
	while (list)
	{
		printf("%d\n", list->data);
		list = list->next;
	}
}
*/
