/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:16:07 by achahid-          #+#    #+#             */
/*   Updated: 2024/05/24 18:37:01 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniHell.h"

char	*find_dollar(char *ptr_token);
void	check_expander_chars(t_expand *d);
int		get_variable_len(char *envp);
char	*retrieve_value(char *envp, char *dollar_tk);
t_bool	check_type(int token_type);

/**
 * find_dollar -
*/
char	*find_dollar(char *ptr_token)
{
	char	c;

	while (*ptr_token)
	{
		c = *(ptr_token + 1);
		if (*ptr_token == '$' && *(ptr_token + 1) != '$'
			&& (ft_isalpha(c) || c == '_'))
			break ;
		ptr_token++;
	}
	return (ptr_token);
}

/**
 * check_expander_chars -
*/
void	check_expander_chars(t_expand *d)
{
	size_t	i;
	char	c;

	i = 0;
	d->dollar_tk_len = 0;
	while (d->ptr_token[i])
	{
		c = d->ptr_token[i + 1];
		if (ft_isalpha(c) || c == '_' || ft_isdigit(c))
		{
			i++;
			d->dollar_tk_len++;
		}
		else
			break ;
	}
}

/**
 * get_variable_len -
*/
int	get_variable_len(char *envp)
{
	int		len_variable;

	len_variable = 0;
	while (*envp != '=')
	{
		envp++;
		len_variable++;
	}
	return (len_variable);
}

/**
 * retrieve_value -
*/
char	*retrieve_value(char *envp, char *dollar_tk)
{
	int	value_len;
	int	i;

	value_len = 0;
	i = 0;
	while (*envp != '=' && *envp)
		envp++;
	envp++;
	while (envp[value_len])
		value_len++;
	dollar_tk = ft_realloc(dollar_tk, value_len);
	while (envp[i])
	{
		dollar_tk[i] = envp[i];
		i++;
	}
	dollar_tk[value_len] = '\0';
	return (dollar_tk);
}

/**
 * check_type -
*/
t_bool	check_type(int token_type)
{
	return (token_type == word_token
		|| token_type == string_token);
}
