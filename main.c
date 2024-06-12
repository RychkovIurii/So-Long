/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:36:12 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/12 17:12:27 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void cleanup_game(t_game *game) {
	if (game->mlx) {
		if (game->wall) mlx_delete_image(game->mlx, game->wall);
		if (game->floor) mlx_delete_image(game->mlx, game->floor);
		if (game->collectible) mlx_delete_image(game->mlx, game->collectible);
		if (game->exit_img) mlx_delete_image(game->mlx, game->exit_img);
		if (game->player) mlx_delete_image(game->mlx, game->player);

		for (size_t i = 0; i < game->map_height; i++)
			free(game->map[i]);
		free(game->map);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;
	ft_memset(&game, 0, sizeof(t_game));

	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}

	if (!ft_validate_file_ext(argv[1])) {
		fprintf(stderr, "Invalid file extension. File must end with .ber\n");
		return 1;
	}

	game.mlx = mlx_init(960, 640, "So Long", true);
	if (!game.mlx)
	{
		fprintf(stderr, "MLX42 initialization failed\n");
		exit(1);
	}
	get_map_height(&game, argv[1]);
	load_map(&game, argv[1]);
	if (!game.map)
	{
		cleanup_game(&game);
		mlx_terminate(game.mlx);
		return (1);
	}

	if (!ft_check_chars(&game)) {
		fprintf(stderr, "Map contains invalid characters\n");
		cleanup_game(&game);
		mlx_terminate(game.mlx);
		return 1;
	}
	load_images(&game);
	parse_map(&game);
	printf("height - %zu. width - %zu.", game.map_height, game.map_width);
	if (!ft_validate_walls(&game))
	{
		cleanup_game(&game);
		mlx_terminate(game.mlx);
		fprintf(stderr, "Map validation failed\n");
		return (1);
	}
/* 	t_position player_start = {game.player_x, game.player_y};
	if (!validate_path(&game, player_start))
	{
		cleanup_game(&game);
		mlx_terminate(game.mlx);
		fprintf(stderr, "No valid path to collect all items and reach the exit\n");
		return (1);
	} */
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	mlx_terminate(game.mlx);
	return (0);
}
