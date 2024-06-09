/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:36:12 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/10 00:14:21 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	
	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	else if (keydata.action == MLX_RELEASE)
		handle_input(game, keydata.key);
}

void	hook(void *param)
{
	t_game	*game;
	
	game = (t_game *)param;
	render_game(game);
}

void	load_map(t_game *game, const char *filename)
{
	int		fd;
	char	*mapline;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Failed to open map file\n");
		return ;
	}
	size_t map_size = 0;
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
			// Освобождаем ранее выделенную память
			while (i > 0) 
				free(game->map[--i]);
			free(game->map);
			free(mapline);
			return;
		}
		free(mapline);
		i++;
	}

	close(fd);
	game->map_width = strlen(game->map[0]);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	init_game(&game);
	load_map(&game, argv[1]); // get_next_line
/* 	if (!is_path_valid(&game)) {
		fprintf(stderr, "Error: No valid path between player, collectibles, and exit\n");
		return 1;
	} */
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_loop_hook(game.mlx, &hook, &game); // Добавляем цикл для отрисовки
	mlx_loop(game.mlx);

	mlx_terminate(game.mlx);
	return (0);
}
