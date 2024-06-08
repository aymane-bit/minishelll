/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:11:47 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/12 14:11:49 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_putstr_fd - function that outputs the string s to the given
 * file descriptor
 * @s: pointer to the string
 * @fd: index of the file descriptor
 * Return: void.
*/
void	ft_putstr_fd(char *s, int fd)
{
	size_t	count;

	if (!s || fd < 0)
		return ;
	count = 0;
	while (s[count])
	{
		ft_putchar_fd(s[count], fd);
		count++;
	}
}
