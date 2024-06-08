/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:29:04 by achahid-          #+#    #+#             */
/*   Updated: 2023/10/31 11:38:51 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
*ft_isdigit - function tests for a decimal digit character
*@c: integer to check in ascii code
*Return: 0 if c is not digit, otherwise 1.
*/
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
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
// 		printf("ft_isdigit: %d\n", ft_isdigit(av[count][0]));
// 		printf("isdigit: %d\n", isdigit(av[count][0]));
// 	}
// 	return (0);
// }
