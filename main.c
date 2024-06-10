/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:36:12 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/10 23:35:57 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>

void	load_map(t_game *game, const char *filename)
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
	game->map = malloc(sizeof(char *) * map_size);
	if (!game->map)
	{
		fprintf(stderr, "Memory allocation error\n");
		return;
	}

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Failed to open map file\n");
		free(game->map);
		return;
	}

	size_t i = 0;
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
			return;
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

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	game.mlx = mlx_init(960, 640, "So Long", true);
	if (!game.mlx) {
		fprintf(stderr, "MLX42 initialization failed\n");
		exit(1);
	}
	load_map(&game, argv[1]);
	if (!game.map)
	{
		mlx_terminate(game.mlx);
		return 1;
	}
	game.steps = 0;
	game.gameover = 0;
	load_images(&game);
	parse_map(&game);
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_loop(game.mlx);
	mlx_delete_image(game.mlx, game.wall);
	mlx_delete_image(game.mlx, game.floor);
	mlx_delete_image(game.mlx, game.collectible);
	mlx_delete_image(game.mlx, game.exit_img);
	mlx_delete_image(game.mlx, game.player);

	for (int i = 0; i < game.map_height; i++)
		free(game.map[i]);
	free(game.map);

	mlx_terminate(game.mlx);
	return (0);
}
