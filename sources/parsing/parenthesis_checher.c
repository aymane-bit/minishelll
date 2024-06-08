/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis_checher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:35:45 by akajjou           #+#    #+#             */
/*   Updated: 2024/06/06 23:18:11 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/miniHell.h"

int		parentheses_checker(token_ptr tokens_list)
{
	int		count;
	token_ptr	tmp;

	count = 0;
	tmp = tokens_list;
	while (tmp != NULL)
	{
		if (tmp->token_type == lbracket_token)
			count++;
		if (tmp->token_type == rbracket_token)
			count--;
		if (count < 0)
		{
			print_error("kssh: Error parentheses");
			return 1;
		}
		tmp = tmp->next;
	}
	if (count != 0)
	{
		print_error("kssh: Error parentheses");
		return 1;
	}
	return 0;
}