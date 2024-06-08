/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:41:32 by achahid-          #+#    #+#             */
/*   Updated: 2023/10/31 12:04:50 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
*ft_isalnum - function that Checks for alphanumeric character
*@c: integer to check in ascii code
*Return: 1 if tests true, otherwise 0.
*/
int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
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
// 		printf("ft_isalnum: %d\n", ft_isalnum(av[count][0]));
// 		printf("isalnum: %d\n", isalnum(av[count][0]));
// 	}
// 	return (0);
// }