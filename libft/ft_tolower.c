/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:35:19 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/01 16:35:20 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_tolower - function that converts an upper-case to the
 * corresponding lower-case letter
 * @c: integer to check in ascii code
 * Return: if c is upper-case return lower-case, othewise the
 * argument remains unchanged
*/
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
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
// 		printf("ft_tolower: %c\n", ft_tolower(a));
// 		printf("tolower: %c\n", tolower(a));
// 	}
//     return (0);
// }
