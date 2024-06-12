/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:53:42 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:01:28 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n > 0)
	{
		*temp = 0;
		n--;
		temp++;
	}
}

/* 
int main () {
	char str[50];
	char str2[50];

	strcpy(str,"This is string.h library function");
	strcpy(str2,"This is string.h library function");
	puts(str);

	bzero(str,7);
	puts(str);
	puts(str + 8);

	ft_bzero(str2,7);
	puts(str2);
	puts(str2 + 8);

	return(0);
} */