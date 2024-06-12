/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:13:10 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:21:54 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sub_len;
	size_t	s_len;
	size_t	i;
	char	*sub;

	if (!(s))
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	sub_len = s_len - start;
	if (len < sub_len)
		sub_len = len;
	sub = (char *)malloc(sizeof(char) * (sub_len + 1));
	if (!(sub))
		return (NULL);
	i = 0;
	while (s[start] && i < sub_len)
	{
		sub[i++] = s[start++];
	}
	sub[i] = '\0';
	return (sub);
}

/* 
int	main(void)
{
	char const src[19] = "0123456789";
	char *result1, *result3, *result5, *result7, *result8;
	char *result2, *result4, *result6;

	result1 = ft_substr(src, 3, 3);
	printf("The substring is: %s\n", result1);
	result2 = ft_substr(src, 3, 0);
	printf("The substring is: %s\n", result2);
	result3 = ft_substr(src, 3, 1);
	printf("The substring is: %s\n", result3);
	result4 = ft_substr(src, 3, 20);
	printf("The substring is: %s\n", result4);
	result5 = ft_substr(src, 0, 3);
	printf("The substring is: %s\n", result5);
	result6 = ft_substr(src, 20, 3);
	printf("The substring is: %s\n", result6);
	result7 = ft_substr(NULL, 3, 3);
	printf("The substring is: %s\n", result7);
	result8 = ft_substr(NULL, 0, 0);
	printf("The substring is: %s\n", result8);
	free(result1);
	free(result2);
	free(result3);
	free(result4);
	free(result5);
	free(result6);
	free(result7);
	free(result8);
	return 0;
} */