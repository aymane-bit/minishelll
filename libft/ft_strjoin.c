/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:11:47 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/08 11:11:51 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_strcpy - function that copies bytes's src into dst
 * @src: source
 * @dst: destination
 * Return: void.
*/
static void	ft_strcpy(char *dst, const char *src)
{
	int	count;

	count = 0;
	while (src[count])
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
}

/**
 * ft_strjoin - function that concatenates s1 and s2
 * and allocate memory for the new string.
 * @s1: The prefix string
 * @s2: The suffix string
 * Return: The new string, othewise NULL
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len_s1;
	size_t	len_s2;
	int		len;

	len_s1 = 0;
	len_s2 = 0;
	if (s1 != NULL)
		len_s1 = ft_strlen(s1);
	if (s2 != NULL)
		len_s2 = ft_strlen(s2);
	len = len_s1 + len_s2;
	new_str = malloc(sizeof(*new_str) * len + 1);
	if (new_str == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strcpy(new_str, s1);
	if (s2 != NULL)
		ft_strcpy(new_str + len_s1, s2);
	return (new_str);
}
/* #include <stdio.h>
int	main(void)
{
	char *ptr;

	ptr = ft_strjoin(NULL, "anas");
	printf("ptr =  %s\n", ptr);
	free(ptr);
	return (0);
} */
