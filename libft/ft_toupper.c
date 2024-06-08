/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:26:21 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/01 16:26:23 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_toupper - function that converts a lower-case to the corresponding
 * upper-case letter
 * @c: integer in to check in ascii code
 * Return: return the converted character, otherwise the argument is returned
 * unchanged.
*/
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
// #include <stdio.h>
// #include <ctype.h>
// int main(int ac, char **av)
// {
//     int count;
// 	int a;

// 	for (count = 1; count < ac; count++)
// 	{
// 		a = atoi(av[count]);
// 		printf("ft_toupper: %c\n", ft_toupper(a));
// 		printf("toupper: %c\n", toupper(a));
// 	}
//     return (0);
// }
