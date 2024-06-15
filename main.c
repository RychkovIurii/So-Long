/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:36:12 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/15 21:08:37 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game		game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
	{
		ft_printf("Error\nUsage: %s <map_file>\n", argv[0]);
		return (1);
	}
	if (!ft_validate_file_ext(argv[1]))
	{
		ft_printf("Error\nExtension. File %s must end with .ber\n", argv[1]);
		return (1);
	}
	game.mlx = mlx_init(1024, 768, "So Long", true);
	if (!game.mlx)
		show_error(&game, "Init error");
	map_handler(&game, argv[1]);
	ft_printf("Hi! Help Nikolai get an internship\n");
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}
