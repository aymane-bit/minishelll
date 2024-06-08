/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:09:42 by achahid-          #+#    #+#             */
/*   Updated: 2024/06/06 20:45:25 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniHell.h"

void	print_error(char *error);
void	quotes_error(int type);

/**
 * print_error -
*/
void	print_error(char *error)
{
	ft_putstr_fd("\033[0;35m", STDERR);
	ft_putstr_fd(error, STDERR);
	ft_putstr_fd("\n", STDERR);
	ft_putstr_fd("\033[0m", STDERR);
}

/**
 * quotes_error -
*/
void	quotes_error(int type)
{
	if (type == doublequote_token)
		print_error("kssh: Error double quotes");
	else if (type == singlequote_token)
		print_error("kssh: Error single quotes");
}
