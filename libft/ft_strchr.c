/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:42:27 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/01 16:42:29 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_strchr - function that locates the first occurence of c
 * @c: integer to check in ascii code
 * @s: pointer to the string to search in
 * Return: pointer to the located character, or NULL if c
 * does not appear in s.
*/
char	*ft_strchr(const char *s, int c)
{
	size_t			count;
	unsigned char	w;

	w = (unsigned char)c;
	if (*s == '\0' && w == '\0')
		return ((char *)s);
	count = 0;
	while (*(s + count))
	{	
		if (*(s + count) == w)
			return ((char *)s + count);
		count++;
		if (!(*(s + count)) && !w)
			return ((char *)s + count);
	}
	return (NULL);
}
/* #include <stdio.h>
#include <string.h>
int main(int ac, char **av)
{
	int count;

	for (count = 1; count < ac; count++)
	{
 		printf("ft_strchr: %s\n", ft_strchr(av[count], '\0'));
 		printf("strchr: %s\n", strchr(av[count], '\0'));
 	}
 	return (0);
} */
