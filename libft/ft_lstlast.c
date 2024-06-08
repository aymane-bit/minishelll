/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:56:53 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/13 10:56:55 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_lstlast - function that returns the last node on a linked list
 * @lst: pointer to head (first node)
 * Return: last node.
*/
t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (lst);
}
/* #include <stdio.h>
int main(void)
{
	t_nodeptr l = NULL;
	t_list		node1;
	t_nodeptr ptr;

	node1.content = "test";
	node1.next = NULL;
	ft_lstadd_front(&l, &node1);
	ptr = ft_lstlast(l);
	printf("content of ptr: %s\n", (char *)ptr->content);
	return (0);
}
 */