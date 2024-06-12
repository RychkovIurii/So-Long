/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:03:50 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:09:18 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_s;
	size_t			i;

	i = 0;
	ptr_s = (unsigned char *)s;
	while (i < n)
	{
		if (*ptr_s == (unsigned char)c)
		{
			return (ptr_s);
		}
		ptr_s++;
		i++;
	}
	return (NULL);
}

/* 
int main () {
	const char str[] = "Hello.Hive.Five";
	const char ch = '.';
	char *result1;
	char *result2;

	result1 = memchr(str, ch, strlen(str));
	result2 = ft_memchr(str, ch, strlen(str));

	printf("String after |%c| is - |%s|\n", ch, result1);
	printf("String after |%c| is - |%s|\n", ch, result2);

	return(0);
} */