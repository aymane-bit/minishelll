/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:08:30 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/12 10:08:31 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * ft_striteri - function that applies function f in each iteration
 * @s: pointer to the string
 * @f: pointer to the function
 * Return: void
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	count;

	if (!s || !f)
		return ;
	count = 0;
	while (s[count])
	{
		(*f)(count, &s[count]);
		count++;
	}
}
