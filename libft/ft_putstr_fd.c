/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:35:50 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:14:37 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/* 
#include <fcntl.h>

int main() {
	int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		perror("Error opening file");
		return 1;
	}
	ft_putstr_fd("Hello Hive", fd);
	close(fd);

	char buffer[11];
	fd = open("test_output.txt", O_RDONLY);
	if (fd == -1) {
		perror("Error opening file");
		return 1;
	}
	int bytes_read = read(fd, buffer, 10);
    buffer[bytes_read] = '\0';

	printf("Expected 'Hello Hive', got '%s'\n", buffer);
	close(fd);

	return 0;
} */