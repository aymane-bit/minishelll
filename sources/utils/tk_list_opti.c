/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_list_opti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:33:44 by achahid-          #+#    #+#             */
/*   Updated: 2024/06/06 20:44:27 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniHell.h"

void		tokens_list_optimizer(token_ptr *tokens_list);
static void	whitespace_remover(token_ptr *tokens_list,
				token_ptr free_node, token_ptr previous);
static void	tokens_order(token_ptr tokens_list);

/**
 * tokens_list_optimizer -
*/
void	tokens_list_optimizer(token_ptr *tokens_list)
{
	token_ptr	tmp;
	token_ptr	free_node;
	token_ptr	previous;

	tmp = *tokens_list;
	free_node = NULL;
	previous = NULL;
	whitespace_remover(tokens_list, free_node, previous);
	tokens_order(*tokens_list);
	// if (*tokens_list != NULL)
	// 	check_tokens(*tokens_list);
}

/**
 * whitespace_remover -
*/
static void	whitespace_remover(token_ptr *tokens_list,
				token_ptr free_node, token_ptr previous)
{
	token_ptr	tmp;

	tmp = *tokens_list;
	while (tmp)
	{
		if (tmp->token_type == whitespace_token || tmp->token_length == 0)
		{
			free_node = tmp;
			previous = tmp->previous;
			tmp = tmp->next;
			if (previous != NULL)
				previous->next = tmp;
			else
				*tokens_list = tmp;
			if (tmp != NULL)
				tmp->previous = previous;
			if (previous == NULL && tmp == NULL)
				*tokens_list = NULL;
			free(free_node->token);
			free(free_node);
			free_node = NULL;
			continue ;
		}
		tmp = tmp->next;
	}
}

/**
 * tokens_reorder -
*/
static void	tokens_order(token_ptr tokens_list)
{
	int	order;

	order = 1;
	while (tokens_list)
	{
		tokens_list->order = order;
		order++;
		tokens_list = tokens_list->next;
	}
}
