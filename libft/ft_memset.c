/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:48:27 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:12:35 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *)b;
	while (len > 0)
	{
		*temp = c;
		len--;
		temp++;
	}
	return (b);
}

/* 
int main () {
	char str[50];
	char str2[50];

	strcpy(str,"This is string.h library function");
	strcpy(str2,"This is string.h library function");
	puts(str);

	memset(str,'$',7);
	puts(str);
	ft_memset(str2,'$',7);
	puts(str2);

	return(0);
} */