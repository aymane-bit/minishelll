/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:21:04 by achahid-          #+#    #+#             */
/*   Updated: 2023/10/31 12:21:06 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
*ft_isprint - function that checks wheter a character
*is a printable in ascii code
*@c: intger to check in ascii code
*Return: 1 if tests true, otherwise 0
*/
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
// 		printf("ft_isprint: %d\n", ft_isprint(av[count][0]));
// 		printf("isprint: %d\n", isprint(av[count][0]));
// 	}
// 	return (0);
// }
