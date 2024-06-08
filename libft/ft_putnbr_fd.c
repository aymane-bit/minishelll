/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:48:18 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/12 14:48:20 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_putnbr_fd - function that outuput n in the given fd
 * @n: integer to output
 * @fd: index of the file descriptor
 * Return: void.
*/
void	ft_putnbr_fd(int n, int fd)
{
	long int	l;

	if (fd < 0)
		return ;
	l = n;
	if (l < 0)
	{
		ft_putchar_fd('-', fd);
		l *= -1;
	}
	if (l >= 0)
	{
		if (l < 10)
		{
			l += 48;
			ft_putchar_fd(l, fd);
		}
		else if (l >= 10)
		{
			ft_putnbr_fd(l / 10, fd);
			ft_putnbr_fd(l % 10, fd);
		}
	}
}
/* int main(void)
{
	void	(*f)(int, int) = ft_putnbr_fd;

	(*f)(0, 1);
	return (0);
} */
