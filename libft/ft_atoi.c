/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:11:17 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/03 14:11:19 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_atoi - function that converts the a string to int representation
 * @str: string to convert
 * Return: the converted number, otherwise zero.
*/
int	ft_atoi(const char *str)
{
	int			sign;
	int			result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}
/* #include <stdio.h>
int main(int ac, char **av)
{
 	int	count;
 	int	at;

 	for (count = 1; count < ac; count++)
 	{
 		at = ft_atoi(av[count]);
 		printf("ft_atoi: %d\n", at);
 		at = atoi(av[count]);
 		printf("atoi: %d\n", at);
 	}
 	return (0);
} */
