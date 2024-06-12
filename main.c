/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:36:12 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/12 23:22:39 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	if (!ft_validate_file_ext(argv[1]))
	{
		printf("Error\nExtension. File must end with %s.ber\n", argv[1]);
		return (1);
	}
	game.mlx = mlx_init(960, 640, "So Long", true);
	if (!game.mlx)
		show_error(&game, "Init error");
	get_map_height(&game, argv[1]);
	load_map(&game, argv[1]);
	if (!ft_check_chars(&game))
		show_error(&game, "Error\nMap contains invalid characters\n");
	load_images(&game);
	parse_map(&game);
	if (!ft_validate_walls(&game))
		show_error(&game, "Error\nMap validation failed\n");
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
	return (0);
}
