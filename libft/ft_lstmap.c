/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:10:14 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/13 15:10:16 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_lstmap - function that iterates in lst and applies the function f
 * on each node's content, creates a new list after each application of f.
 * del is used to delete the content of the node if needed
 * @lst: pointer to head (first node)
 * @f: pointer to the function which we apply on each node's content
 * @del: pointer to the function that deletes the node's content
 * Return: the new list, otherwise NULL.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_nodeptr	new_list;
	t_nodeptr	node;

	new_list = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		node = ft_lstnew((*f)(lst->content));
		if (node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}
