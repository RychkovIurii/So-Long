/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_tolower.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: irychkov <irychkov@student.hive.fi>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/04/16 21:55:03 by irychkov		  #+#	#+#			 */
/*   Updated: 2024/04/16 21:55:03 by irychkov		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_tolower(int argument)
{
	if (argument > 64 && argument < 91)
		return (argument + 32);
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
	result = tolower(c);
	result2 = ft_tolower(c);
	printf("tolower(%c) = %c\n", c, result);
	printf("tolower(%c) = %c\n", c, result2);

	c = 'q';
	result = tolower(c);
	result2 = ft_tolower(c);
	printf("tolower(%c) = %c\n", c, result);
	printf("tolower(%c) = %c\n", c, result2);

	c = '!';
	result = tolower(c);
	result2 = ft_tolower(c);
	printf("tolower(%c) = %c\n", c, result);
	printf("tolower(%c) = %c\n", c, result2);

	return 0;
} */