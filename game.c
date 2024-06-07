/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:22:31 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/07 15:48:32 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_game(t_game *game)
{
	game->mlx = mlx_init(640, 480, "So Long", true);
	if (!game->mlx) {
		//Error handler
		return ;
	}

	game->player.img = mlx_load_png("textures/character.png");
	game->player.width = 32;
	game->player.height = 32;

	game->wall.img = mlx_load_png("textures/wall.png");
	game->wall.width = 32;
	game->wall.height = 32;

	game->floor.img = mlx_load_png("textures/floor.png");
	game->floor.width = 32;
	game->floor.height = 32;

	game->collectible.img = mlx_load_png("textures/collectible.png");
	game->collectible.width = 32;
	game->collectible.height = 32;

	game->exit.img = mlx_load_png("textures/exit.png");
	game->exit.width = 32;
	game->exit.height = 32;

	game->player_x = 0;
	game->player_y = 0;

	mlx_image_to_window(game->mlx, game->player.img, game->player_x * game->player.width, game->player_y * game->player.height);
}
