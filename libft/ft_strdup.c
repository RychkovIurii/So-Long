/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:38:31 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:17:46 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dst;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(s1);
	dst = (char *)malloc(sizeof(char) * (src_len + 1));
	if (dst == NULL)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/* 
int main()
{
	char source[] = "Hi Hive";
	char source1[] = "Hi Hive";

	char *target = strdup(NULL);
	char *target1 = ft_strdup(NULL);
	
	printf("%s - original\n", target);
	printf("%s - mine", target1);
	return 0;
} */