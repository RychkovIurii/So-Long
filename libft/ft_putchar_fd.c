/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:53:36 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:12:12 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* 
#include <fcntl.h>

void ft_putchar_fd(char c, int fd);

int main() {
	int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		perror("Error opening file");
		return 1;
	}
	ft_putchar_fd('a', fd);
	close(fd);

	char buffer[10];
	fd = open("test_output.txt", O_RDONLY);
	if (fd == -1) {
		perror("Error opening file");
		return 1;
	}
	read(fd, buffer, 1);
	buffer[1] = '\0';

	printf("Expected 'a', got '%s'\n", buffer);
	close(fd);

	return 0;
} */