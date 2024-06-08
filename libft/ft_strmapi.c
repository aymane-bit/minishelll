/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:56:20 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/12 09:56:21 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_strmapi - function that applies function f to each character
 * if the string s, and create a new string.
 * @s: pointer to the string
 * @f: pointer to the function
 * Return: The string created, otherwise NULL.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	count;
	char	*str;
	size_t	len;

	count = 0;
	len = 0;
	if (s)
		len = ft_strlen(s);
	str = malloc(sizeof(*str) * len + 1);
	if (!str)
		return (NULL);
	while (s[count])
	{
		str[count] = (*f)(count, s[count]);
		count++;
	}
	str[count] = '\0';
	return (str);
}
/* char ft_f(unsigned int l, char c)
{
	return (l + c);
}
#include <stdio.h>
int main(void)
{
	char (*func)(unsigned int, char) = &ft_f;
	char *str = ft_strmapi("anas", func);

	printf("str: %s\n", str);
	return (0);
} */
