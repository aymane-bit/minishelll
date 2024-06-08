/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:06:28 by achahid-          #+#    #+#             */
/*   Updated: 2023/10/31 15:06:30 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
*ft_memcpy - function that copies n bytes from src to dst
*@src: source
*@dst: destination
*Return: destination
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		count;
	unsigned char	*ptr;
	unsigned char	*ptr1;

	if (!src && !dst)
		return (NULL);
	ptr = (unsigned char *)src;
	ptr1 = (unsigned char *)dst;
	count = 0;
	while (count < n)
	{
		ptr1[count] = ptr[count];
		count++;
	}
	return (ptr1);
}
/* #include <stdio.h>
int	main(void)
{
	char dst[10];
	char *src = "1337";
	ft_memcpy(src + 5, (void *)src, 3);
	printf("dest is: %s\n", dst);
	memcpy(src + 5, (void *)src, 3);
	printf("dest is: %s\n", dst);
	return (0);
} */
