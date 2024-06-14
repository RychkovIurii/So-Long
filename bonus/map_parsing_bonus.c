/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:13:12 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/14 16:28:59 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	b_add_instance(t_game *game, mlx_image_t *img, int x, int y)
{
	if (mlx_image_to_window(game->mlx, img,
			x * img->width, y * img->height) < 0)
		b_show_error(game, "Failed to add image instance to window");
}

static void	b_handle_map_element(t_game *game, char elem, size_t x, size_t y)
{
	if (elem == '1')
		b_add_instance(game, game->wall, x, y);
	else if (elem == '!')
		b_add_instance(game, game->enemy, x, y);
	else if (elem == '0')
		b_add_instance(game, game->floor, x, y);
	else if (elem == 'C')
	{
		b_add_instance(game, game->floor, x, y);
		b_add_instance(game, game->collectible, x, y);
	}
	else if (elem == 'E')
		b_add_instance(game, game->exit_img, x, y);
	else if (elem == 'P')
	{
		b_add_instance(game, game->floor, x, y);
		game->player_x = x;
		game->player_y = y;
	}
}

void	b_parse_map(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			b_handle_map_element(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
	b_add_instance(game, game->player, game->player_x, game->player_y);
}
