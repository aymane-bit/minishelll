/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:44:21 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/13 10:44:22 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_lstsize - function that counts the number of nodes in a list
 * @lst: pointer to head (first node)
 * Return: number of nodes.
*/
int	ft_lstsize(t_list *lst)
{
	size_t	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/* #include <stdio.h>
int main(void)
{
	t_nodeptr	list;
	t_list		node1;
	t_list		node2;
	int			len;

	node1.content = "na";
	node1.next = &node2;
	node2.content = "flsdh";
	node2.next = NULL;
	list = &node1;
	len = ft_lstsize(list);
	printf("length of the linked list: %d\n", len);
	return (0);
} */
