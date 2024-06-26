/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:13:12 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/14 14:39:01 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	add_instance(t_game *game, mlx_image_t *img, int x, int y)
{
	if (mlx_image_to_window(game->mlx, img,
			x * img->width, y * img->height) < 0)
		show_error(game, "Failed to add image instance to window");
}

static void	handle_map_element(t_game *game, char elem, size_t x, size_t y)
{
	if (elem == '1')
		add_instance(game, game->wall, x, y);
	else if (elem == '0')
		add_instance(game, game->floor, x, y);
	else if (elem == 'C')
	{
		add_instance(game, game->floor, x, y);
		add_instance(game, game->collectible, x, y);
	}
	else if (elem == 'E')
		add_instance(game, game->exit_img, x, y);
	else if (elem == 'P')
	{
		add_instance(game, game->floor, x, y);
		game->player_x = x;
		game->player_y = y;
	}
}

void	parse_map(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			handle_map_element(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
	add_instance(game, game->player, game->player_x, game->player_y);
}
