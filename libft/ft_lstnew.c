/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:10:05 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/13 10:10:07 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_lstnew - function that allocates and returns a new node
 * @content: The content to create the new node with
 * Return: The new node, otherwise NULL.
*/
t_list	*ft_lstnew(void *content)
{
	t_nodeptr	head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
/* #include <stdio.h>
int main(void)
{
	t_nodeptr h = ft_lstnew("anas");

	printf("%s\n", (char *)h->content);
	return (0);
} */
