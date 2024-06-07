/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:35:03 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/07 15:53:40 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
	//Escape, obstacles, collectible validation. Render map.
void	handle_input(t_game *game, int key)
{
	if (key == MLX_KEY_W)
		game->player_y -= 1;
	else if (key == MLX_KEY_S)
		game->player_y += 1;
	else if (key == MLX_KEY_A)
		game->player_x -= 1;
	else if (key == MLX_KEY_D)
		game->player_x += 1;
	//render_game(game);
}
