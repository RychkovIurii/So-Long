/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:45:42 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:02:50 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int argument)
{
	if ((argument > 64 && argument < 91) || (argument > 96 && argument < 123))
		return (1);
	else if (argument > 47 && argument < 58)
		return (1);
	else
		return (0);
}

/* 
#include <stdio.h>
#include <ctype.h>
int main (void)
{
	char s = '!';
	int orig, mine;
	orig = isalnum(s);
	mine = ft_isalnum(s);
	printf("%d is original\n", orig);
	printf("%d is mine", mine);
} */