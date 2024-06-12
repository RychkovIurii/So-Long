/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:48:32 by irychkov          #+#    #+#             */
/*   Updated: 2024/05/03 12:15:31 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
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
	write(fd, "\n", 1);
}

/*
#include <fcntl.h>

int main() {
	int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		perror("Error opening file");
		return 1;
	}
	ft_putendl_fd("Hello Hive", fd);
	close(fd);

	char buffer[12];
	fd = open("test_output.txt", O_RDONLY);
	if (fd == -1) {
		perror("Error opening file");
		return 1;
	}
	int bytes_read = read(fd, buffer, 11);
	buffer[bytes_read] = '\0';

	printf("Expected:\nHello Hive\nGot:\n%s", buffer);
	close(fd);

	return 0;
} */