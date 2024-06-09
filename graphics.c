/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:35:03 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/10 00:13:43 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_input(t_game *game, int key)
{
	int	old_x;
	int	old_y;
	
	old_x = game->player_x;
	old_y = game->player_y;

	if (key == MLX_KEY_W && game->player_y > 0 && game->map[game->player_y - 1][game->player_x] != '1')
		game->player_y -= 1;
	else if (key == MLX_KEY_S && game->player_y < game->map_height - 1 && game->map[game->player_y + 1][game->player_x] != '1')
		game->player_y += 1;
	else if (key == MLX_KEY_A && game->player_x > 0 && game->map[game->player_y][game->player_x - 1] != '1')
		game->player_x -= 1;
	else if (key == MLX_KEY_D && game->player_x < game->map_width - 1 && game->map[game->player_y][game->player_x + 1] != '1')
		game->player_x += 1;

	if (old_x != game->player_x || old_y != game->player_y)
	{
		game->steps += 1;
		game->is_running = true;
	}
	else
		game->is_running = false;
	render_game(game);
}
