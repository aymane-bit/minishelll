/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:48:06 by achahid-          #+#    #+#             */
/*   Updated: 2023/11/11 14:48:09 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_check_sep(char c, char sep)
{
	return (c == sep);
}

static int	ft_strings(const char *s, char sep)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[count])
	{
		while (s[count] && ft_check_sep(s[count], sep))
			count++;
		if (s[count])
			i++;
		while (s[count] && !ft_check_sep(s[count], sep))
			count++;
	}
	return ((int)i);
}

static int	ft_strtosep(const char *s, char sep)
{
	int	count;

	count = 0;
	while (s[count] && !ft_check_sep(s[count], sep))
		count++;
	return (count);
}

static char	*ft_put_word(const char *s, char sep, char **dup, int i)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strtosep(s, sep);
	dup[i] = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup[i])
	{
		while (--i >= 0)
		{
			free(dup[i]);
		}
		free(dup);
		return (NULL);
	}
	while (count < len)
	{
		dup[i][count] = s[count];
		count++;
	}
	dup[i][count] = '\0';
	return (dup[i]);
}

char	**ft_split(const char *s, char c)
{
	char	**av;
	int		count;

	count = 0;
	av = (char **)malloc(sizeof(char *) * (ft_strings(s, c) + 1));
	if (!av)
		return (NULL);
	while (*s)
	{
		while (*s && ft_check_sep(*s, c))
			s++;
		if (*s)
		{
			if (ft_put_word(s, c, av, count) == NULL)
				return (NULL);
			count++;
		}
		while (*s && !ft_check_sep(*s, c))
			s++;
	}
	av[count] = NULL;
	return (av);
}

/* #include <stdio.h>
int main(void)
{
    char str[] = "Trouipille ";
    char **av;

    av = ft_split(str, ',');
	for (int count = 0; count < 2; count++)
		printf("av[%d]: %s\n", count, av[count]);
    return (0);
} */
