/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:24:27 by achahid-          #+#    #+#             */
/*   Updated: 2023/10/31 15:02:25 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
*ft_memset - function that writes len bytes of value c (in ascii code)
*to the string b
*@b: pointer
*@c: integer needed to fill len bytes on b
*@len: bytes to be filled
*Return: pointer to the memory area b.
*/
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			count;
	char			*ptr;

	ptr = (char *)b;
	count = 0;
	while (count < len)
		ptr[count++] = c;
	return (b);
}
/* #include <stdio.h>
#include <string.h>
int main(void)
{
	char str[] = "1337";
	char str1[] = "1337";

 	printf("ft_memset: %s\n", (char *)ft_memset(str, 256, 20));
 	printf("memset: %s\n", (char *)memset(str1, 256, 20));
	printf("-------------------------------------\n");
	printf("str[0]: %d\n", str[0]);
	printf("str[0]: %d\n", str1[0]);
	return (0);
} */
