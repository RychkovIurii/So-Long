/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:56:43 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/11 08:10:10 by irychkov         ###   ########.fr       */
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

void	load_map(t_game *game, const char *filename)
{
	int		fd;
	char	*mapline;
	size_t	i;
	size_t	map_size;

	map_size = game->map_height;
	game->map = malloc(sizeof(char *) * map_size);
	if (!game->map)
	{
		fprintf(stderr, "Memory allocation error\n");
		return ;
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Failed to open map file\n");
		free(game->map);
		return ;
	}
	i = 0;
	mapline = get_next_line(fd);
	while (i < map_size && mapline)
	{
		game->map[i] = ft_strdup(mapline);
		if (!game->map[i])
		{
			fprintf(stderr, "Memory allocation error\n");
			close(fd);
			while (i > 0)
				free(game->map[--i]);
			free(game->map);
			free(mapline);
			return ;
		}
		free(mapline);
		mapline = get_next_line(fd);
		i++;
	}

	close(fd);
	game->map_width = strlen(game->map[0]);
}

void	parse_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->score = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				add_instance(game->mlx, game->wall, x, y);
			else if (game->map[y][x] == '0')
				add_instance(game->mlx, game->floor, x, y);
			else if (game->map[y][x] == 'C')
			{
				add_instance(game->mlx, game->collectible, x, y);
				game->score++;
			}
			else if (game->map[y][x] == 'E')
				add_instance(game->mlx, game->exit_img, x, y);
			else if (game->map[y][x] == 'P')
			{
				add_instance(game->mlx, game->player, x, y);
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
	game->current_score = 0;
}
