/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:02:00 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/01 17:02:02 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_strrchr - function that locates the last occurence of c
 * @c: integer to check in ascii code
 * @s: pointer to string
 * Return: pointer to the located char, or NULL if the char
 * does not appear in the string.
*/
char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	w;

	w = (unsigned char)c;
	len = ft_strlen(s) - 1;
	if (*(s + len + 1) == '\0' && w == '\0')
		return ((char *)s + len + 1);
	while (len >= 0)
	{	
		if (s[len] == w)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// int main(int ac, char **av)
// {
// 	int count;

// 	for (count = 1; count < ac; count++)
// 	{
// 		printf("ft_strrchr: %s\n", ft_strrchr(av[count], '\0'));
// 		printf("strrchr: %s\n", strrchr(av[count], '\0'));
// 	}
// 	return (0);
// }
