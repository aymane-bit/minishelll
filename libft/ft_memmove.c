/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:19:12 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/01 12:19:13 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_memmove - function that copies len bytes form src to dst
 * @src: source
 * @dst: destination
 * @len: number of bytes to copy form src to dst
 * Return: original value of dst
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst1;
	const char	*src1;

	dst1 = dst;
	src1 = src;
	if (dst1 < src1)
	{
		while (len)
		{
			*dst1++ = *src1++;
			len--;
		}
	}
	else if (dst1 > src1)
	{
		dst1 += len;
		src1 += len;
		while (len)
		{
			*(--dst1) = *(--src1);
			len--;
		}
	}
	return (dst);
}
/* #include <stdio.h>
#include <string.h>
int main(void)
{
 	char dst[3];
 	char src[20] = "ansnnfdsflksf";
 	void *ptr, *ptr1;

 	ptr = (char *)ft_memmove(dst, src, 3);
 	ptr1 = (char *)mmemove(dst, src, 10);
 	printf("ft_mmemove: %s\n", ptr);
 	printf("memmove: %s\n", ptr1);
 	return (0);
}
 */