/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 22:18:40 by akajjou           #+#    #+#             */
/*   Updated: 2024/06/08 23:37:19 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/miniHell.h"

token_ptr    echo_skipper(token_ptr tmp)
{
        while (tmp && (tmp->token_type == 5 || tmp->token_type == 4))
            tmp = tmp->next;
        return (tmp);
}

void	ft_echo(token_ptr tokens_list)
{
    token_ptr	tmp;
    int			n_flag;

    n_flag = 0;
    tmp = tokens_list;
    if (tmp->next && strcmp(tmp->next->token, "-n") == 0)
    {
        n_flag = 1;
        tmp = tmp->next;
    }
    tmp = tmp->next;
    while (tmp)
    {
        if (tmp->token_type == 5 || tmp->token_type == 4)
            tmp = echo_skipper(tmp);
        if (tmp == NULL)
            break ;
        ft_putstr_fd(tmp->token, 1);
        if (tmp->next)
            ft_putstr_fd(" ", 1);
        tmp = tmp->next;
    }
    if (n_flag == 0)
        ft_putstr_fd("\n", 1);
}
