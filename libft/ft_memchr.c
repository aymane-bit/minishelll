/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:28:33 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/02 11:28:35 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_memchr - function that locates the first occurence of c in string s
 * @s: pointer to the string
 * @c: integer to check in ascii code
 * @n: number of bytes to search in.
 * Return: void pointer.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*ptr;
	unsigned char			w;
	size_t					count;

	ptr = (const unsigned char *)s;
	w = (unsigned char)c;
	count = 0;
	while (count < n)
	{
		if (ptr[count] == w)
			return ((void *)&ptr[count]);
		count++;
	}
	return (NULL);
}
/* #include <string.h>
#include <stdio.h>

int main(int ac, char **av)
{
 	int count = 1;
 	const char *str, *ptr;

 	while (count < ac)
 	{
 		str = ft_memchr(av[count], 0, 20);
 		ptr = memchr(av[count], 0, 20);
 		printf("My func is: %s\n", str);
 		printf("Original func is: %s\n", ptr);
 		count++;
 	}
 	return (0);
} */
