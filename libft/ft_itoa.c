/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:00:47 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/11 15:00:49 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/**
 * ft_zero - function that fills the first 2 bytes with '0' and '\0'
 * @ptr: pointer to the buffer
 * Return: void
*/
static void	ft_zero(char *ptr)
{
	ptr[0] = '0';
	ptr[1] = '\0';
}

/**
 * ft_negetive - function that handles case if n < 0
 * @ptr: pointer to the buffer
 * @n: number to be converted
 * @length: length of n in bytes
 * Return: void.
*/
static void	ft_negative(char *ptr, int length, int n)
{
	long int	t;

	t = (long int)n;
	ptr[0] = '-';
	t = -t;
	length++;
	ptr[length--] = '\0';
	while (length > 0)
	{
		ptr[length--] = t % 10 + 48;
		t /= 10;
	}
}

/**
 * ft_lenght - function that counts the length of n in digits
 * @n: integer to be converted
 * @l: pointer to the length of the buffer
 * @temp: variable that holds n value
 * Return: void.
*/
static void	ft_length(int temp, int *l)
{
	int	count;

	count = 0;
	*l = count;
	if (temp == 0)
		count++;
	while (temp != 0)
	{
		temp /= 10;
		count++;
	}
	*l = count;
}

/**
 * ft_positive - function that handles the case of n > 0
 * @str: pointer to the buffer
 * @length: length of the buffer
 * @n: integer to be converted
 * Return: void.
*/
static void	ft_positive(char *str, int length, int n)
{
	while (length >= 0)
	{
		str[length--] = n % 10 + 48;
		n /= 10;
	}
}

/**
 * ft_itoa - function that converts an interger to string
 * @n: The integer to convert
 * Return: pointer to the allocated memory.
*/
char	*ft_itoa(int n)
{
	char	*str;
	int		length;

	ft_length(n, &length);
	str = malloc(sizeof(*str) * length + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		free(str);
		str = malloc(sizeof(char) * length + 2);
		if (!str)
			return (NULL);
		ft_negative(str, length, n);
		return (str);
	}
	else if (n == 0)
	{
		ft_zero(str);
		return (str);
	}
	str[length--] = '\0';
	ft_positive(str, length, n);
	return (str);
}
/* #include <stdio.h>
int main(void)
{
    int l = 943857;
    char *str;

    str = ft_itoa(l);
    printf("str: %s\n", str);
    return (0);
} */
