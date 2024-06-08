/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akajjou <akajjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:29:00 by akajjou           #+#    #+#             */
/*   Updated: 2024/05/29 07:27:23 by akajjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/miniHell.h"

void   handler(int signum)
{
    write(STDOUT, "\n", 1);
    write(STDOUT, "kssh$ ", 6);
}
void  ft_handler(int signum)
{
    struct termios term;

    // Get the current terminal attributes
    if (tcgetattr(STDIN_FILENO, &term) < 0) 
    {
        perror("tcgetattr");
        exit(EXIT_FAILURE);
    }
    // Disable the quit character (Ctrl+\)
    term.c_cc[VQUIT] = _POSIX_VDISABLE;
    // Set the modified terminal attributes
    if (tcsetattr(STDIN_FILENO, TCSANOW, &term) < 0) 
    {
        perror("tcsetattr");
        exit(EXIT_FAILURE);
    }
}

void   signal_handler()
{
    signal(SIGINT, handler);
    signal(SIGQUIT, ft_handler);
}