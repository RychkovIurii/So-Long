/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:18:26 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:03:42 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int argument)
{
	if (argument > 47 && argument < 58)
		return (1);
	else
		return (0);
}

/* 
#include <stdio.h>
#include <ctype.h>
int main (void)
{
	char s = 'c';
	int orig, mine;
	orig = isdigit(s);
	mine = ft_isdigit(s);
	printf("%d is original\n", orig);
	printf("%d is mine", mine);
} */