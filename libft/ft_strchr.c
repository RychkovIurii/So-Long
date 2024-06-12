/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:14:02 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:13:16 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr_s;

	ptr_s = (char *)s;
	while (*ptr_s != (char)c)
	{
		if (*ptr_s == '\0')
		{
			return (NULL);
		}
		ptr_s++;
	}
	return (ptr_s);
}

/*
#include <string.h>
#include <stdio.h>

int main () {
	const char str[] = "Hello.Hive.Five";
	const char ch = '.';
	const char ch2 = 'D';
	const char ch3 = '\0';
	char *result, *result2, *result3;
	char *result4, *result5, *result6;

	result = strchr(str, 1024);
	result2 = ft_strchr(str, 1024);

	printf("String after orig |%c| is - |%s|\n", ch, result);
	printf("String after mine |%c| is - |%s|\n", ch, result2);

	result3 = strchr(str, ch2);
	result4 = ft_strchr(str, ch2);

	printf("String after orig |%c| is - |%s|\n", ch2, result3);
	printf("String after mine |%c| is - |%s|\n", ch2, result4);

	result5 = strchr(str, ch3);
	result6 = ft_strchr(str, ch3);

	printf("String after orig |%c| is - |%s|\n", ch3, result5);
	printf("String after mine |%c| is - |%s|\n", ch3, result6);
	
	return(0);
} */