/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:10:16 by eproust           #+#    #+#             */
/*   Updated: 2024/11/09 19:25:13 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

int	ft_list_size(t_list *begin_list)
{
	int		count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	node1;
	t_list	node2;
	t_list	node3;

	node1.data = "1";
	node2.data = "2";
	node3.data = "3";

	node1.next = &node2;
	node2.next = &node3;
	node3.next = NULL;

	printf("List size: %d\n", ft_list_size(&node1));
}
*/
