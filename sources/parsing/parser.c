/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:30:47 by achahid-          #+#    #+#             */
/*   Updated: 2024/06/07 23:09:46 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/miniHell.h"

int    ft_type_check(token_ptr tokens_list)
{
	if (pipe_checker(tokens_list) == 1)
		return 1;
	if (redirections_checker(tokens_list) == 1)
		return 1;
	if (semicolon_checker(tokens_list) == 1)
		return 1;
	if (backslash_checker(tokens_list) == 1)
		return 1;
	if (parentheses_checker(tokens_list) == 1)
		return 1;
	if (heredoc_append_checker(tokens_list) == 1)
		return 1;
	
	return 0;
}
void 		build_in(token_ptr tokens_list)
{
	if (strcmp(tokens_list->token, "echo") == 0)
		ft_echo(tokens_list);
	else if (strcmp(tokens_list->token, "exit") == 0)
		exit(1);
	// else if (ft_strcmp(tokens_list->token, "cd") == 0)
	// 	ft_cd(tokens_list);
	// else if (ft_strcmp(tokens_list->token, "pwd") == 0)
	// 	ft_pwd();
	// else if (ft_strcmp(tokens_list->token, "export") == 0)
	// 	ft_export(tokens_list);
	// else if (ft_strcmp(tokens_list->token, "unset") == 0)
	// 	ft_unset(tokens_list);
	// else if (ft_strcmp(tokens_list->token, "env") == 0)
	// 	ft_env();
}


int	parser_tokens(token_ptr tokens_list)
{
	if (tokens_list == NULL)
		return  0;
	if (ft_type_check(tokens_list) == 1)
		return 1;
	build_in(tokens_list);
	return 0;
}


