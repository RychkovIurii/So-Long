/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:18:10 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:02:49 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int argument)
{
	if ((argument > 64 && argument < 91) || (argument > 96 && argument < 123))
		return (1);
	else
		return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int main (void)
{
	char s = 'Q';
	int orig, mine;
	orig = isalpha(s);
	mine = ft_isalpha(s);
	printf("%d is original\n", orig);
	printf("%d is mine", mine);
} */