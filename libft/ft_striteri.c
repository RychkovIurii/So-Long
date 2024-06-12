/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:51:10 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:17:21 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* 
void test_toupper(unsigned int i, char *c) {
	if (*c >= 'a' && *c <= 'z') {
		*c = *c - 32;
	}
}

int main(void) {
	char str[] = "Hello Hive!";

	ft_striteri(str, test_toupper);
	printf("%s\n", str);

	return 0;
} */