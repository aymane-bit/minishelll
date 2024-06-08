/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:47:34 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/01 17:47:36 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_strncmp - function that compares not more that n chars
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * @n: number of bytes to be compared, chars after '\0' not considered
 * Return: integer greater than, equal to, or less than 0, according as
 * s1 is greater than, equal to, or less than s2
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	if (n == 0)
		return (n);
	count = 0;
	n -= 1;
	while (n-- && (s1[count] || s2[count]))
	{
		if (s1[count] - s2[count] == 0)
		{
			count++;
			continue ;
		}
		break ;
	}
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	int a;
// 	a = ft_strncmp("bnbb", "bnba", 10);
// 	printf("%d\n", a);
// 	a = strncmp("bnbb", "bnba", 10);
// 	printf("%d\n", a);
// 	return (0);
// }
