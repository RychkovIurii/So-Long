/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:31:54 by irychkov          #+#    #+#             */
/*   Updated: 2024/04/29 17:45:00 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*b;
	size_t	total;

	total = count * size;
	if (count != 0 && size != 0 && (size != (total / count)))
		return (NULL);
	b = (void *)malloc(total);
	if (b)
		ft_bzero(b, total);
	return (b);
}

/* 
int main () {
	int i, n;
	int *a;
	int *a2;

	printf("Number of elements to be entered:");
	scanf("%d",&n);

	a = (int*)calloc(n, sizeof(int));
	for( i=0 ; i < n ; i++ ) {
		printf("%d ",a[i]);
	}
	a2 = (int*)ft_calloc(n, sizeof(int));
	for( i=0 ; i < n ; i++ ) {
		printf("%d ",a2[i]);
	}
	free( a );
	free( a2 );
	
	return(0);
} */