/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:05:53 by irychkov          #+#    #+#             */
/*   Updated: 2024/04/21 15:34:05 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strcounter(char const *s, char c)
{
	size_t	elements;

	elements = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s && *s != c)
		{
			elements++;
			while (*s && *s != c)
				s++;
		}
		while (*s && *s == c)
			s++;
	}
	return (elements);
}

static void	free_array(char **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

static char	**ft_helper(char const *s, char c, size_t i, char **result)
{
	const char	*start;

	while (*s)
	{
		if (*s && *s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			result[i] = (char *)malloc(sizeof(char) * (s - start + 1));
			if (!result[i])
			{
				free_array(result, i);
				return (NULL);
			}
			ft_strlcpy(result[i], start, s - start + 1);
			i++;
		}
		while (*s && *s == c)
			s++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	char		**result;

	i = 0;
	result = (char **)malloc(sizeof(char *) * (ft_strcounter(s, c) + 1));
	if (!result || !s)
		return (NULL);
	return (ft_helper(s, c, i, result));
}
/* 
int	main(void)
{
	char	str[20] = "b    hello hive ";
	char	c = ' ';
	size_t	counter;
	char	**result;

	counter = ft_strcounter(str, c);
	printf("%zu\n", counter);
	result = ft_split(str, c);
	if (result)
	{
		for (size_t i = 0; result[i]; i++)
			printf("%s\n", result[i]);
		for (size_t i = 0; result[i]; i++)
			free(result[i]);
		free(result);
	}
	return 0;
} */