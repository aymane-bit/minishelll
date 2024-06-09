/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 05:59:00 by akajjou           #+#    #+#             */
/*   Updated: 2024/06/08 22:38:11 by akajjou          ###   ########.fr       */
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
				print_error("syntax error near unexpected token `newline'");
				return (1);
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
			&& (tmp->next->token_type == 8 || tmp->next->token_type == 9))
	{
		if (tmp->next->token_type == 8)
			print_error("syntax error near unexpected token `<'");
		else
			print_error("syntax error near unexpected token `>'");
	}
	return 0;
}

int	redirections_checker_3(token_ptr tokens_list) // > ls >
{
	token_ptr tmp;

	tmp = tokens_list;
	while (tmp)
	{
		if (tmp->token_type == 8 || tmp->token_type == 9)
		{
			if (tmp->next->token_type == 10 || tmp->next->token_type == 11)
			{
				if (tmp->next->token_type == 10)
					print_error("syntax error near unexpected token `<<'");
				else
					print_error("syntax error near unexpected token `>>'");
				return (1);
			}
		}
		tmp = tmp->next;
	}
	return 0;
}

int	redirections_checker(token_ptr tokens_list)
{
	if (redirections_checker_1(tokens_list) == 1)
		return (1);
	if (redirections_checker_2(tokens_list) == 1)
		return (1);
	if (redirections_checker_3(tokens_list) == 1)
		return (1);
	return 0;
}
