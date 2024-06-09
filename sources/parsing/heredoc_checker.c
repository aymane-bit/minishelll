/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:13:04 by akajjou           #+#    #+#             */
/*   Updated: 2024/06/08 21:16:47 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/miniHell.h"

int		heredoc_checker_first(token_ptr tokens_list)
{
	token_ptr	tmp;

	tmp = tokens_list;
	while (tmp)
	{
		if (tmp->token_type == 10)
		{
			if (tmp->next == NULL)
			{
				print_error("syntax error near unexpected token `newline'");
				return (1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}
int		append_checker_second(token_ptr tokens_list)
{
	token_ptr	tmp;

	tmp = tokens_list;
	while (tmp)
	{
		if (tmp->token_type == 11)
		{
			if (tmp->next == NULL)
			{
				print_error("syntax error near unexpected token `newline'");
				return 1;
			}
		}
		tmp = tmp->next;
	}
	return 0;
}
int		heredoc_max_checker(token_ptr tokens_list)
{
	token_ptr	tmp;
	int			count;

	count = 0;
	tmp = tokens_list;
	while (tmp)
	{
		if (tmp->token_type == 10)
			count++;		
		tmp = tmp->next;
	}
	if (count > 16)
	{
		print_error("minishell : maximum here-document count exceeded");
		return 1;
	}
	return 0;
}
int		heredoc_next_checker(token_ptr tokens_list)
{
	token_ptr	tmp;

	tmp = tokens_list;
	while (tmp && tmp->next)
	{
		if (tmp->token_type == 10 && tmp->next->token_type == 10)
		{
			print_error("minishell : syntax error near unexpected token `newline'");
			return 1;
		}
	tmp = tmp->next;		
	}
	return 0;
}

int     heredoc_append_checker(token_ptr tokens_list)
{
    if (heredoc_checker_first(tokens_list) == 1)
        return 1;
    if (append_checker_second(tokens_list) == 1)
        return 1;
	if (heredoc_max_checker(tokens_list) == 1)
		return (1);
	if (heredoc_next_checker(tokens_list) == 1)
		return 1;
    return 0;
}
