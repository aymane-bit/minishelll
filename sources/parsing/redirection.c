/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 05:59:00 by akajjou           #+#    #+#             */
/*   Updated: 2024/06/06 18:19:04 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniHell.h"

int	redirections_checker_1(token_ptr tokens_list)
{
	token_ptr tmp;

	tmp = tokens_list;
	while(tmp)
	{
		if (tmp->token_type == 8 || tmp->token_type == 9)
		{
			if (tmp->next == NULL)
			{
				ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
				return 1;
			}
			if (tmp->next->token_type == 0)
				while (tmp->next->token_type == 0)
				{
					tmp = tmp->next;
					if (tmp->next == NULL)
					{
						ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
						return 1;
					}
				}
		}
		tmp = tmp->next;
	}
	return 0;
}

int 	redirections_checker_2(token_ptr tokens_list) // > > ls
{
	token_ptr tmp;

	tmp = tokens_list;
	if ((tmp->token_type == 8 || tmp->token_type == 9)
			&& (tmp->next->token_type != 8 && tmp->next->token_type != 9))
	{
		while(tmp)
		{
			if (tmp->next->token_type == 0)
				while (tmp->next->token_type == 0)
					tmp = tmp->next;
			if (tmp->token_type == 0)
				tmp = tmp->next;
			if (tmp->token_type == 8 || tmp->token_type == 9)
			{
				ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
				return 1;
			}
		tmp = tmp->next;
		}
	}
	return 0;
}

int	redirections_checker(token_ptr tokens_list)
{
	if (redirections_checker_1(tokens_list) == 1)
		return 1;
	if (redirections_checker_2(tokens_list) == 1)
		return 1;
	return 0;
}
