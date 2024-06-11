/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:13:12 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/11 09:17:35 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	game->score = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				add_instance(game->mlx, game->wall, x, y);
			else if (game->map[y][x] == '0')
				add_instance(game->mlx, game->floor, x, y);
			else if (game->map[y][x] == 'C')
			{
				add_instance(game->mlx, game->collectible, x, y);
				game->score++;
			}
			else if (game->map[y][x] == 'E')
				add_instance(game->mlx, game->exit_img, x, y);
			else if (game->map[y][x] == 'P')
			{
				add_instance(game->mlx, game->player, x, y);
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
	game->current_score = 0;
}
