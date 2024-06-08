/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:43:35 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/13 14:43:37 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_lstclear - function that deletes and frees a given node and
 * every successor of that node must be freed, using the function del
 * @lst: pointer to pointer to a given node
 * @del: function to use to delete node's contents
 * Return: void.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_nodeptr	node;

	if (lst == NULL)
		return ;
	while ((*lst) != NULL)
	{
		node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node;
	}
}
