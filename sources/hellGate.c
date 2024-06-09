/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hellGate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:30:07 by achahid-          #+#    #+#             */
/*   Updated: 2024/06/08 21:13:06 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniHell.h"

/**
 * $() - Error
 * (pwd) - should be threated. as well as ((((cmd)))). (akajjou's work)
 * 
 * Optimize the token list
 * 	1 - skip all spaces and tokens with length == 0. (DONE)
 * 	2 - reorder the list.
*/
void	check_tokens(token_ptr print_tk)
{
	while (print_tk != NULL)
	{
		printf("------------------------------\n");
		printf("token: %s\n", print_tk->token);
		printf("order: %d\n", print_tk->order);
		printf("type: %d\n", print_tk->token_type);
		printf("lenght: %d\n", print_tk->token_length);
		if (print_tk->previous != NULL)
			printf("previous: %s\n", print_tk->previous->token);
		else if (print_tk->previous == NULL)
			printf("previous: NULL\n");
		printf("------------------------------\n");
		print_tk = print_tk->next;
	}
}

int	main(int ac, char **av, char **envp)
{
	char		*user_input;
	token_ptr	tokens_list;

	signal_handler();
	while (true)
	{
		user_input = readline("kssh$ ");
		if (user_input == NULL)
			exit(EXIT_SUCCESS);
		if (ft_strncmp(user_input, "\0", 1) != 0)
			add_history(user_input);
		tokens_list = lexer(user_input);
		tokens_expander(tokens_list, envp);
		tokens_list_optimizer(&tokens_list);
		// check_tokens(tokens_list);
		// exit(1);
		parser_tokens(tokens_list);
		free_tokens(tokens_list);
		free(user_input);
	}
	return (EXIT_SUCCESS);
}
