/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:50:06 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:03:27 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int argument)
{
	if (argument >= 0 && argument <= 127)
		return (1);
	else
		return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int main (void)
{
	//char s = 'Q';
	int orig, mine;
	orig = isascii(190);
	mine = ft_isascii(190);
	printf("%d is original\n", orig);
	printf("%d is mine", mine);
} */