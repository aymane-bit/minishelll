/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:08:34 by achahid-          #+#    #+#             */
/*   Updated: 2023/10/31 12:08:37 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
*ft_isascii - function that checks for an ascii character
*@c: integer to checks in ascii code
*Return: 1 if tests true, otherwise 0
*/
int	ft_isascii(int c)
{
	if (!(c > 127) && c >= 0)
		return (1);
	return (0);
}
// #include <stdio.h>
// #include <ctype.h>
// int main(int ac, char **av)
// {
// 	int count;

// 	for (count = 1; count < ac; count++)
// 	{
// 		printf("ft_isascii: %d\n", ft_isascii(av[count][0]));
// 		printf("isascii: %d\n", isascii(av[count][0]));
// 	}
// 	return (0);
// }
