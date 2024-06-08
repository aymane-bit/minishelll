/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:17:15 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/13 11:17:17 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_lstadd_back - funtion that adds a node at the end of a linked list
 * @lst: pointer to pointer to head (first node)
 * @new: the node to add at the end
 * Return: void.
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_nodeptr	lastnode;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst != NULL)
	{
		lastnode = ft_lstlast(*lst);
		lastnode->next = new;
		return ;
	}
	*lst = new;
}
