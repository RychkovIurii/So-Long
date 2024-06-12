/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:45:39 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:03:39 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int argument)
{
	if (argument >= 32 && argument <= 126)
		return (1);
	else
		return (0);
}

/* 
#include <stdio.h>
#include <ctype.h>
int main (void)
{
	char s = '\t';
	int orig, mine;
	orig = isprint(s);
	mine = ft_isprint(s);
	printf("%d is original\n", orig);
	printf("%d is mine", mine);
} */