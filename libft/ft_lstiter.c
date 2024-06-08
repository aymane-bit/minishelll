/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:01:01 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/13 15:01:03 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_lstiter - function that iterates the list lst and applies the function f
 * on the content of each node
 * @lst: pointer to head (first node)
 * @f: pointer to the function to apply on each node
 * Return: void.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_nodeptr	node;

	if (lst == NULL)
		return ;
	node = lst;
	while (node != NULL)
	{
		(*f)(node->content);
		node = node->next;
	}
}
