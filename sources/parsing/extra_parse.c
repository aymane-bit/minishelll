/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 06:55:10 by akajjou           #+#    #+#             */
/*   Updated: 2024/06/06 22:32:31 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniHell.h"

int     semicolon_checker(token_ptr tokens_list)
{
    token_ptr   tmp;
    
    tmp = tokens_list;
    while (tmp)
    {
        if (ft_strchr(tmp->token, ';') != NULL && tmp->token_type != 3)
        {
            ft_putstr_fd("minishell: syntax error near unexpected token `;'\n", 2);
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

int     backslash_checker(token_ptr tokens_list)
{
    token_ptr   tmp;
    
    tmp = tokens_list;
    while (tmp)
    {
        if (ft_strchr(tmp->token, '\\') != NULL)
        {
            ft_putstr_fd("minishell: syntax error near unexpected token `\\'\n", 2);
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}
/*
int     parentheses_checker2(token_ptr tokens_list)
{
    token_ptr   tmp;
    
    tmp = tokens_list;
    while (tmp)
    {
        if (ft_strchr(tmp->token, '(') != NULL && tmp->token_type != 3)
        {
            
        }
    
        tmp = tmp->next;
    }
    return 0;
}*/

int		parentheses_checker(token_ptr tokens_list)
{
	token_ptr	tmp;
	int			open;
	int			close;

	tmp = tokens_list;
	open = 0;
	close = 0;
	while (tmp)
	{
		if (ft_strchr(tmp->token, '(') != NULL && tmp->token_type != 3)
			open++;
		if (ft_strchr(tmp->token, ')') != NULL && tmp->token_type != 3)
			close++;
		tmp = tmp->next;
	}
	if (open != close)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `('\n", 2);
		return 1;
	}
	return 0;
}
