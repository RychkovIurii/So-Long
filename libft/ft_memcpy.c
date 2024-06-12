/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:39:01 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:11:36 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	temp_src = (unsigned char *)src;
	temp_dst = (unsigned char *)dst;
	while (n > 0)
	{
		*temp_dst = *temp_src;
		n--;
		temp_dst++;
		temp_src++;
	}
	return (dst);
}

/* int main () {
	const char src[50] = "Hive is here";
	char dest[50];
	const char src2[50] = "Hive is here";
	char dest2[50];

	strcpy(dest,"Heloooo!!");
	strcpy(dest2,"Heloooo!!");
	printf("Before memcpy dest = %s\n", dest);

	memcpy(dest, src, strlen(src)+1);
	printf("After memcpy dest = %s\n", dest);
	ft_memcpy(dest2, src2, ft_strlen(src2)+1);
	printf("After ft_memcpy dest2 = %s\n", dest2);

	return(0);
}
*/
/* 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *src = "Hello, world!";
	char dst[100];

	// Тестирование на NULL для src
	printf("Testing src = NULL...\n");
	if (ft_memcpy(dst, NULL, 5) == NULL)
		printf("ft_memcpy passed src = NULL test\n");
	else
		printf("ft_memcpy failed src = NULL test\n");

	printf("Testing src = NULL...\n");
	if (memcpy(dst, NULL, 5) == NULL)
		printf("memcpy passed src = NULL test\n");
	else
		printf("memcpy failed src = NULL test\n");

	 // Тестирование на NULL для dst
	printf("Testing dst = NULL...\n");
	if (ft_memcpy(NULL, src, 5) == NULL)
		printf("ft_memcpy passed dst = NULL test\n");
	else
		printf("ft_memcpy failed dst = NULL test\n");

	printf("Testing dst = NULL...\n");
	if (memcpy(NULL, src, 5) == NULL)
		printf("memcpy passed dst = NULL test\n");
	else
		printf("memcpy failed dst = NULL test\n");

	// Тестирование на NULL для обоих src и dst
	printf("Testing both src = NULL and dst = NULL...\n");
	if (ft_memcpy(NULL, NULL, 5) == NULL)
		printf("ft_memcpy passed both NULL test\n");
	else
		printf("ft_memcpy failed both NULL test\n");

	printf("Testing both src = NULL and dst = NULL...\n");
	if (memcpy(NULL, NULL, 5) == NULL)
		printf("memcpy passed both NULL test\n");
	else
		printf("memcpy failed both NULL test\n");

	return 0;
} */