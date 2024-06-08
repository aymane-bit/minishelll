/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:03:35 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/02 12:03:37 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_memcmp - function that compares byte s1 against byte s2
 * @n: number of bytes
 * @s1: first string
 * @s2: second string
 * Return: 0 if s1 and s2 are identical, otherwise returns the difference
 * between the first two differing bytes.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*ptr1;
	const char	*ptr2;
	size_t		count;

	ptr1 = (const char *)s1;
	ptr2 = (const char *)s2;
	count = 0;
	while (n)
	{
		if (ptr1[count] != ptr2[count])
			return ((unsigned char) ptr1[count] - (unsigned char) ptr2[count]);
		n--;
		count++;
	}
	return (0);
}
/* #include <stdio.h>
#include <string.h>
int main(int ac, char **av)
{
	int count;

	for (count = 1; count < ac - 1; count++)
	{
		int a, b;
 		a = ft_memcmp(av[count], av[count + 1], 3);
 		b = memcmp(av[count], av[count + 1], 3);
 		printf("My func returns: %d\n", a);
 		printf("Original func returns: %d\n", b);
 	}
 	return (0);
} */
