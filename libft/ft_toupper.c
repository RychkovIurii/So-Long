/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:55:08 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:21:25 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int argument)
{
	if (argument > 96 && argument < 123)
		return (argument - 32);
	else
		return (argument);
}

/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	char c, result, result2;

	c = 'Q';
	result = toupper(c);
	result2 = ft_toupper(c);
	printf("toupper(%c) = %c\n", c, result);
	printf("toupper(%c) = %c\n", c, result2);

	c = 'q';
	result = toupper(c);
	result2 = ft_toupper(c);
	printf("toupper(%c) = %c\n", c, result);
	printf("toupper(%c) = %c\n", c, result2);

	c = '!';
	result = toupper(c);
	result2 = ft_toupper(c);
	printf("toupper(%c) = %c\n", c, result);
	printf("toupper(%c) = %c\n", c, result2);

	return 0;
}*/