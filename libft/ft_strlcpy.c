/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:33:05 by achahid-          #+#    #+#             */
/*   Updated: 2023/10/31 15:33:07 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
*ft_strlcpy - function that copy strings form src to dst
*src: source
*dst: destination
*@dstsize: destination size in bytes
*Return: length of src
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	count;

	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	count = 0;
	while (count < dstsize - 1 && src[count])
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (len_src);
}
