/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:36:12 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/15 21:09:02 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game		game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
	{
		ft_printf("Error\nUsage: %s <map_file>\n", argv[0]);
		return (1);
	}
	if (!b_ft_validate_file_ext(argv[1]))
	{
		ft_printf("Error\nExtension. File %s must end with .ber\n", argv[1]);
		return (1);
	}
	b_map_handler(&game, argv[1]);
	ft_printf("Hi! Help Nikolai get an internship\n");
	mlx_key_hook(game.mlx, &b_my_keyhook, &game);
	mlx_loop(game.mlx);
	b_cleanup_game(&game);
	return (0);
}
