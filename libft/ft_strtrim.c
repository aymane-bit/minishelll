/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:25:53 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/08 11:25:55 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_strrev - function that reverses the indexs of an array
 * @str: pointer to the string to reverse
 * Return: void.
*/
static void	ft_strrev(char *str)
{
	size_t	len;
	size_t	count;
	char	temp;

	len = ft_strlen(str) - 1;
	count = 0;
	while (count < len)
	{
		temp = str[count];
		str[count++] = str[len];
		str[len--] = temp;
	}
}
/**
 * ft_check_dup - function that checks if the char s_check
 * may appear in set chars.
 * @set: set of chars where to check
 * @s_check: the char to check in set
 * Return: 0 if s_check found in set, otherwise 1.
*/

static int	ft_check_dup(char s_check, const char *set)
{
	size_t	count;

	count = 0;
	while (set[count])
	{
		if (set[count] == s_check)
			return (0);
		count++;
	}
	return (1);
}

/**
 * ft_realloc - function that realloc str in another memory size
 * to fit the content inside str, and avoid any memory leak
 * @str: pointer to the string to realloc
 * @temp: pointer to the memory area to frees
 * Return: pointer to the new memory area, otherwise NULL.
*/
static char	*ft_realloc(char	*str, char	*temp)
{
	char	*s;

	s = ft_strdup(str);
	free(temp);
	if (!s)
		return (NULL);
	return (s);
}
/**
 * ft_strtrim - funtction that removes the leading (at the beginning)
 * and trailing (at the end) set of characters.
 * @s1: string to be trimmed.
 * @set: The reference set of chars to be trimmed.
 * Return: copy of s1.
*/

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*ptr;
	char	*str;
	char	*s;
	char	*temp;

	ptr = ft_strdup(s1);
	if (!ptr)
		return (NULL);
	temp = ptr;
	while (ft_check_dup(*ptr, set) == 0 && *ptr)
		ptr++;
	if (!*ptr)
	{
		s = ft_realloc(ptr, temp);
		return (s);
	}
	ft_strrev(ptr);
	while (ft_check_dup(*ptr, set) == 0 && *ptr)
		ptr++;
	ft_strrev(ptr);
	str = ft_realloc(ptr, temp);
	return (str);
}
/* #include <stdio.h>
int main(void)
{
	char *str = ft_strtrim("    sss  sss", " s");

	printf("str = %s\n", str);
	return (0);
} */
