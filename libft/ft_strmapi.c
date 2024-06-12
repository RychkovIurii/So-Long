/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:06:20 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:19:35 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* 
char	test_toupper(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return c - 32;
	else
		return c;
}

int	main(void)
{
	char str[12] = "Hello Hive!";
	char *result;
	result = ft_strmapi(str, test_toupper);
	printf("%s", result);
	free(result);
	return (0);
} */