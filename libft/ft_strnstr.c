/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:29:29 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/02 12:29:31 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_strnstr - function that locates the first occurence of find in
 * haystack, where the search is limited to the first len chars of
 * haystack or the null-terminated string in needle.
 * @haystak: pointer to the string where to search
 * @needle: pointer to the string to search
 * @len: number of bytes
 * Return: if needle is empty haystack is returned, NULL if needle
 * doesn't appear in haystack, otherwise a pointer to the first char
 * of the first occurence of needle is returned.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;

	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return ((char *)haystack);
	if (haystack == NULL && *needle)
	{
		while (len--)
		{
			if ((*haystack - *needle) == 0)
				return ((char *)haystack);
			needle++;
			haystack++;
		}
	}
	while (len >= len_needle && *haystack)
	{
		if (!ft_strncmp(haystack, needle, len_needle))
			return ((char *)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char *ptr;
// 	char *ptr1;

// 	ptr = ft_strnstr("a1 3a3a", "3\0", 2);
// 	ptr1 = strnstr("a1 3a3a", "3\0", 2);
// 	printf("ft_strnstr: %s\n", ptr);
// 	printf("strnstr: %s\n", ptr1);
// 	return (0);
// }
