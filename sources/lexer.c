/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:30:17 by achahid-          #+#    #+#             */
/*   Updated: 2024/05/05 10:30:19 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniHell.h"

token_ptr	lexer(char *user_input);
t_bool		string_tokens(char **user_input, token_ptr *tokens_head,
				int type, int *order);
t_bool		char_tokens(char **user_input, token_ptr *tokens_head,
				int type, int order);

/**
 * lexer - Lexical Analyser; tokenize the
 * readed input into simpliest tokens
 * @user_input: full command taken from the prompt or from an fd
 * 
 * Return: a list of tokens.
*/
token_ptr	lexer(char *user_input)
{
	token_ptr	tokens_head;
	int			order;
	int			type;
	t_bool		s;

	tokens_head = NULL;
	order = 1;
	s = true;
	while (*user_input)
	{
		type = get_type(*user_input);
		if (type == leftred_token && type == get_type(*(user_input + 1)))
			s = token_create(&user_input, &tokens_head, heredoc_token, order++);
		else if (type == rightred_token && type == get_type(*(user_input + 1)))
			s = token_create(&user_input, &tokens_head, append_token, order++);
		else if (type == singlequote_token || type == doublequote_token)
			s = string_tokens(&user_input, &tokens_head, type, &order);
		else
			s = char_tokens(&user_input, &tokens_head, type, order++);
		if (*user_input)
			user_input++;
	}
	if (s == false)
		return (NULL);
	return (tokens_head);
}

/**
 * string_tokens - handler of complicated cases
 * such as: string_token for doublequote_token
 * and singlequote_token
 * @user_input: double pointer to the input
 * @tokens_head: double pointer to the list of tokens
 * @type: token's type
 * @order: order of token on the input
 * 
 * Return: void.
*/
t_bool	string_tokens(char **user_input, token_ptr *tokens_head,
			int type, int *order)
{
	t_bool	s;
	int		len;

	s = true;
	s = token_create(user_input, tokens_head, type, *order);
	if (s == false)
		return (s);
	*order += 1;
	*user_input += 1;
	if (get_type(**user_input) != type)
	{
		if (token_create(user_input, tokens_head,
				string_token, *order) == false)
			return (move_user_input(user_input), false);
		*order += 1;
		*user_input += 1;
	}
	if (get_type(**user_input) != type)
		return (false);
	s = token_create(user_input, tokens_head, type, *order);
	*order += 1;
	return (s);
}

/**
 * char_token - create the token based on his type
 * @user_input: double pointer to user_input
 * @tokens_head: pointer to the list of tokens
 * @type: token's type
 * @order: order of the token on user_input
 * 
 * Return: boolean.
*/
t_bool	char_tokens(char **user_input, token_ptr *tokens_head,
						int type, int order)
{
	t_bool	s;

	s = true;
	if (type == whitespace_token)
		s = token_create(user_input, tokens_head, whitespace_token, order);
	else if (type == pipe_token)
		s = token_create(user_input, tokens_head, pipe_token, order);
	else if (type == lbracket_token)
		s = token_create(user_input, tokens_head, lbracket_token, order);
	else if (type == rbracket_token)
		s = token_create(user_input, tokens_head, rbracket_token, order);
	else if (type == leftred_token)
		s = token_create(user_input, tokens_head, leftred_token, order);
	else if (type == rightred_token)
		s = token_create(user_input, tokens_head, rightred_token, order);
	else
		s = token_create(user_input, tokens_head, word_token, order);
	return (s);
}
