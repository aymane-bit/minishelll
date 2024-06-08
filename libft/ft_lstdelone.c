/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdelone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:02:18 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/13 14:02:20 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

/**
 * ft_lstdelone - frees the memory of the node's content using the function
 * del
 * @lst: pointer to the node to frees
 * @del: pointer to the function that frees lst
 * Return: void.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	(*del)(lst->content);
	free(lst);
}
/* void	del(void *str)
{
	free(str);
}
int main(void)
{
	t_nodeptr	node;

	node = malloc(sizeof(t_list));
	node->content = ft_strdup("anas");
	node->next = NULL;
	ft_lstdelone(node, del);
	return (0);
} */
