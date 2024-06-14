/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:56:43 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/14 16:28:18 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	b_get_map_height(t_game *game, const char *filename)
{
	int		fd;
	char	*mapline;
	size_t	map_size;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		b_show_error(game, "FD error");
	map_size = 0;
	mapline = get_next_line(fd);
	while (mapline)
	{
		free(mapline);
		map_size++;
		mapline = get_next_line(fd);
	}
	close(fd);
	if (map_size < 3)
		b_show_error(game, "Mapsize error");
	game->map_height = map_size;
}

static void	b_init_map(t_game *game, const char *filename)
{
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		b_show_error(game, "Memory allocation error");
	game->fd = open(filename, O_RDONLY);
	if (game->fd < 0)
		b_show_error(game, "Failed to open map file");
	game->map[game->map_height] = NULL;
}

static void	b_read_map_lines(t_game *game)
{
	char	*mapline;
	size_t	i;

	i = 0;
	mapline = get_next_line(game->fd);
	while (i < game->map_height && mapline)
	{
		game->map[i] = ft_strtrim(mapline, "\n");
		if (!game->map[i])
		{
			free(mapline);
			b_show_error(game, "Memory allocation error");
		}
		free(mapline);
		mapline = get_next_line(game->fd);
		i++;
	}
}

void	b_load_map(t_game *game, const char *filename)
{
	b_init_map(game, filename);
	b_read_map_lines(game);
	close(game->fd);
	game->map_width = ft_strlen(game->map[0]);
	if (!game->map)
		b_show_error(game, "Map loading error");
}
