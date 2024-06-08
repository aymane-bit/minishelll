/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:27:03 by achahid-          #+#    #+#             */
/*   Updated: 2023/10/31 11:39:15 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
*ft_isalpha - function that checks for alphabetic characters
*@c: integer to check in ascii code
*Return: 0 if the char tests false, and 0 if char test true.
*/
int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/* #include <stdio.h>
#include <ctype.h>
int main(void)
{
	printf("ft_isalpha: %d\n", ft_isalpha(320));
	printf("isalpha: %d\n", isalpha(320));
	return (0);
} */
