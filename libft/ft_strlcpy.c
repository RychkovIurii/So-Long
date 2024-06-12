/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:17:51 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:16:19 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/* 
#include <string.h>

int main(void) {
	char dst[20];
	char dst2[20];
	const char *src = "Hello, World!";
	size_t result;
	size_t result2;

	// Test case 1: Normal case
	printf("Test case 1: Normal case\n");
	result = ft_strlcpy(dst, src, sizeof(dst));
	printf("Copied string: %s\n", dst);
	printf("Length of copied string: %zu\n\n", result);
	result2 = strlcpy(dst2, src, sizeof(dst2));
	printf("Copied string: %s\n", dst2);
	printf("ORIG Length of copied string: %zu\n\n", result2);

	// Test case 2: src is NULL
	//printf("Test case 2: src is NULL\n");
	//result = ft_strlcpy(dst, NULL, sizeof(dst));
	//printf("Length of copied string: %zu\n\n", result);
	//result2 = strlcpy(dst2, NULL, sizeof(dst2));
	//printf("ORIG Length of copied string: %zu\n\n", result2);

	// Test case 3: dst is NULL
	printf("Test case 3: dst is NULL\n");
	result = ft_strlcpy(NULL, src, sizeof(dst));
	printf("Length of copied string: %zu\n\n", result);
	result2 = strlcpy(NULL, src, sizeof(dst2));
	printf("ORIG Length of copied string: %zu\n\n", result2);
	return 0;
} */