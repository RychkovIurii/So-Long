/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:36:12 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/11 08:11:18 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
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
		mlx_terminate(game.mlx);
		return (1);
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
