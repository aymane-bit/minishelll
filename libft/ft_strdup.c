/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:10:12 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/03 17:11:00 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_strdup - function that allocates sufficient memory for a copy of
 * the string s1, does the copy, and returns a pointer to it.
 * @s1: String to copy
 * Return: pointer to the allocated block of memory
*/
char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	size_t	count;

	len = ft_strlen(s1);
	str = malloc(sizeof (*str) * len + 1);
	if (str == NULL)
		return (NULL);
	count = 0;
	while (*s1)
	{
		str[count++] = *s1++;
	}
	*(str + count) = '\0';
	return (str);
}
// #include <stdio.h>
// int main(void)
// {
// 	char *str = ft_strdup("anas");
// 	if (str == NULL)
// 		return (-1);
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
