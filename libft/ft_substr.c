/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:09:14 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/05 15:09:16 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_strncpy - function that copies n bytes form s to dst
 * @s: source
 * @dst: destination
 * Return: void.
*/
static void	ft_strncpy(char *dst, char const *s, int bytes)
{
	int	count;

	count = 0;
	while (count < bytes)
	{
		dst[count] = s[count];
		count++;
	}
	dst[count] = '\0';
}

/**
 * ft_substr - function that create a substring from s.
 * @start: starting index of the substring
 * @len: max length of the substring
 * Return: The substring, othewise NULL.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub_s;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		return (ft_strdup(""));
	}
	if (len > s_len - start)
	{
		len = s_len - start;
	}
	sub_s = malloc(len + 1);
	if (!sub_s)
		return (NULL);
	ft_strncpy(sub_s, s + start, len);
	sub_s[len] = '\0';
	return (sub_s);
}

/* #include <stdio.h>
int main(void)
{
	char *str = "I'm a software engineer";
	char *ptr;

	ptr = ft_substr(str, 2, 3);
	printf("ptr = %s\n", ptr);
	free(ptr);
	return (0);
}
 */
