/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:09:30 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/10 00:14:38 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_game(t_game *game)
{
	for (int y = 0; y < game->map_height; y++) {
		for (int x = 0; x < game->map_width; x++) {
			if (game->map[y][x] == '1') {
				mlx_image_to_window(game->mlx, game->wall.frames[0], x * game->wall.width, y * game->wall.height);
			} else if (game->map[y][x] == '0') {
				mlx_image_to_window(game->mlx, game->floor.frames[0], x * game->floor.width, y * game->floor.height);
			} else if (game->map[y][x] == 'C') {
				mlx_image_to_window(game->mlx, game->collectible.frames[game->collectible.current_frame], x * game->collectible.width, y * game->collectible.height);
				game->collectible.current_frame = (game->collectible.current_frame + 1) % game->collectible.frame_count;
			} else if (game->map[y][x] == 'E') {
				mlx_image_to_window(game->mlx, game->exit.frames[0], x * game->exit.width, y * game->exit.height);
			}
		}
	}

	t_sprite *current_sprite = game->is_running ? &game->player_run : &game->player_idle;
	mlx_image_to_window(game->mlx, current_sprite->frames[current_sprite->current_frame], game->player_x * current_sprite->width, game->player_y * current_sprite->height);
	current_sprite->current_frame = (current_sprite->current_frame + 1) % current_sprite->frame_count;
}
