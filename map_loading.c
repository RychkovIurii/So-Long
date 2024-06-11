/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:56:43 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/11 09:16:23 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_height(t_game *game, const char *filename)
{
	int		fd;
	char	*mapline;
	size_t	map_size;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Failed to open map file\n");
		return ;
	}
	map_size = 0;
	mapline = get_next_line(fd);
	while (mapline)
	{
		free(mapline);
		map_size++;
		mapline = get_next_line(fd);
	}
	close(fd);

	game->map_height = map_size;
}

static int	init_map(t_game *game, const char *filename)
{
	game->map = malloc(sizeof(char *) * game->map_height);
	if (!game->map)
	{
		fprintf(stderr, "Memory allocation error\n");
		return (0);
	}
	game->fd = open(filename, O_RDONLY);
	if (game->fd < 0)
	{
		fprintf(stderr, "Failed to open map file\n");
		free(game->map);
		return (0);
	}
	return (1);
}

static int	read_map_lines(t_game *game)
{
	char	*mapline;
	size_t	i;

	i = 0;
	mapline = get_next_line(game->fd);
	while (i < game->map_height && mapline)
	{
		game->map[i] = ft_strdup(mapline);
		if (!game->map[i])
		{
			fprintf(stderr, "Memory allocation error\n");
			free(mapline);
			return (0);
		}
		free(mapline);
		mapline = get_next_line(game->fd);
		i++;
	}
	return (1);
}

static void	cleanup_map_on_error(t_game *game)
{
	close(game->fd);
	while (game->map && --game->map_height >= 0)
		free(game->map[game->map_height]);
	free(game->map);
}

void	load_map(t_game *game, const char *filename)
{
	if (!init_map(game, filename))
		return ;
	if (!read_map_lines(game))
	{
		cleanup_map_on_error(game);
		return ;
	}
	close(game->fd);
	game->map_width = strlen(game->map[0]);
}
