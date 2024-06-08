/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:31:44 by achahid-          #+#    #+#             */
/*   Updated: 2024/06/03 14:31:46 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniHell.h"

void	free_tokens(token_ptr tokens_list)
{
	token_ptr	tmp;

	while (tokens_list)
	{
		tmp = tokens_list;
		free(tokens_list->token);
		tokens_list = tokens_list->next;
		free(tmp);
	}
}
