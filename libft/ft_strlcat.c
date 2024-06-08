/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:06:56 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/01 16:06:58 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_strlcat - function that concatenates strings
 * @dst: destination
 * @src: source
 * @dstsize: destination size in bytes
 * Return: intial length of dst + src
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	temp;
	size_t	count;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	temp = dst_len;
	count = 0;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[count] && temp < dstsize - 1)
		dst[temp++] = src[count++];
	dst[temp] = '\0';
	return (dst_len + src_len);
}
/* #include <stdio.h>
#include <string.h>
int main(void)
{
 	char dst[11] = "Hello ";
 	char dst1[11] = "Hello ";
 	char src[] = "World!";
 	int size = ft_strlcat(dst, src, 11);
 	int size1 = strlcat(dst1, src, 11);

 	printf("dst[%d], %s\n", size, dst);
 	printf("dst[%d], %s\n", size1, dst1);
 	return (0);

} */
