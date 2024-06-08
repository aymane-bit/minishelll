/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:25:57 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/03 15:25:59 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_calloc - function that allocats enough sapce for count objects that are
 * size bytes of memory
 * @count: number of blocks
 * @size: size of each block
 * Return: pointer to the allocated memory.
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > (SIZE_MAX / size))
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*#include <stdio.h>
int main(void)
{
 	int *str;
	int *ptr;

	str = ft_calloc(-5, -5);
	ptr = calloc(-5, -5);
	printf("%d\n", str[0]);
	printf("%d\n", str[1]);
	printf("%d\n", str[2]);
	printf("%d\n", ptr[0]);
	printf("%d\n", ptr[1]);
 	printf("%d\n", ptr[2]);
 	return (0);
} */
