/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:13:15 by achahid-          #+#    #+#             */
/*   Updated: 2024/05/24 18:36:46 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniHell.h"

void	tokens_expander_helper(token_ptr tokens_list, char **envp,
			t_expand d);
int		dollars_count(char *token);
t_bool	string_handler(token_ptr *tokens_list);
int		get_biggest_len(char *envp, char *dollar_tk);
void	data_move_helper(t_expand *data, char **token);

/**
 * tokens_expander_helper -
*/
void	tokens_expander_helper(token_ptr tokens_list, char **envp,
			t_expand d)
{
	while (tokens_list != NULL)
	{
		if (string_handler(&tokens_list) == false)
			return ;
		d.dollars_count = dollars_count(tokens_list->token);
		while (d.dollars_count-- > 0)
		{
			if (check_type(tokens_list->token_type) == false)
				return ;
			d.ptr_token = find_dollar(tokens_list->token);
			if (*d.ptr_token == '\0')
				break ;
			check_expander_chars(&d);
			if (d.dollar_tk_len == 0)
				break ;
			d.tmp_dollar_len = d.dollar_tk_len;
			d.dollar_tk = extract_dollar_token(d.ptr_token, d.dollar_tk,
					d.dollar_tk_len);
			d.dollar_tk = get_value(d.dollar_tk, &d.dollar_tk_len, envp);
			tokens_list->token = expanding(d.dollar_tk, tokens_list->token,
					d.tmp_dollar_len);
			tokens_list->token_length = ft_strlen(tokens_list->token);
		}
		tokens_list = tokens_list->next;
	}
}

/**
 * dollars_count -
*/
int	dollars_count(char *token)
{
	int	dollars;

	dollars = 0;
	while (*token)
	{
		if (*token == '$' && *(token + 1) != '$')
			dollars++;
		token++;
	}
	return (dollars);
}

/**
 * string_hanlder - handle the execution of the
 * expansion of dollar sign, in double quoted string
*/
t_bool	string_handler(token_ptr *tokens_list)
{
	if ((*tokens_list)->token_type == doublequote_token)
	{
		*tokens_list = (*tokens_list)->next;
		if ((*tokens_list) == NULL
			|| (*tokens_list)->token_type == doublequote_token)
			return (false);
	}
	else if ((*tokens_list)->token_type == singlequote_token)
	{
		*tokens_list = (*tokens_list)->next;
		if ((*tokens_list) == NULL
			|| (*tokens_list)->token_type == singlequote_token)
			return (false);
		if ((*tokens_list)->token_type == string_token)
			*tokens_list = (*tokens_list)->next;
		return (false);
	}
	return (true);
}

/**
 * get_biggest_len -
*/
int	get_biggest_len(char *envp, char *dollar_tk)
{
	int	envp_len;
	int	dollar_tk_len;

	envp_len = get_variable_len(envp);
	dollar_tk_len = ft_strlen(dollar_tk);
	if (envp_len > dollar_tk_len)
		return (envp_len);
	return (dollar_tk_len);
}

/**
 * data_move_helper -
*/
void	data_move_helper(t_expand *data, char **token)
{
	data->new_token[data->i] = token[0][0];
	*token += 1;
	data->i++;
}
