/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:04:48 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:11:56 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	temp_src = (unsigned char *)src;
	temp_dst = (unsigned char *)dst;
	if (temp_src < temp_dst)
	{
		temp_dst += len - 1;
		temp_src += len - 1;
		while (len > 0)
		{
			*temp_dst = *temp_src;
			temp_dst--;
			temp_src--;
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

/* 
int main () {

	char src[] = "Hello, World!";
	char dest[20];
	char src2[] = "Hello, World!";
	char dest2[20];

	// Test case 1: Non-overlapping memory regions
	printf("Test case 1: Non-overlapping memory regions\n");
	memmove(dest, src, strlen(src) + 1);
	printf("Copied string: %s\n", dest);
	ft_memmove(dest2, src2, strlen(src2) + 1);
	printf("Copied string: %s\n", dest2);

	// Test case 2: Overlapping memory regions (source before destination)
	printf("Overlapping memory regions (source before destination)\n");
	memmove(dest + 2, dest, strlen(dest) + 1);
	printf("Copied string: %s\n", dest);
	ft_memmove(dest2 + 2, dest2, strlen(dest2) + 1);
	printf("Copied string: %s\n", dest2);

	// Test case 3: Overlapping memory regions (destination before source)
	printf("Overlapping memory regions (destination before source)\n");
	memmove(dest, dest + 2, strlen(dest) + 1);
	printf("Copied string: %s\n", dest);
	ft_memmove(dest2, dest2 + 2, strlen(dest2) + 1);
	printf("Copied string: %s\n", dest2);

	return(0);
} */