/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:52:16 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/10 23:31:31 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_map_and_images(int x, int y, t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[y][x] = 'P';
	game->player->instances[0].x = x * TILE_SIZE;
	game->player->instances[0].y = y * TILE_SIZE;
}

static void	handle_move(int x, int y, t_game *game)
{
	size_t	i;
	
	if (game->map[y][x] == '1')
		return;
	else if (game->map[y][x] == 'E' && game->current_score != game->score)
	{
		printf("Collect all items first!\n");
		return;
	}
	else if (game->map[y][x] == 'E' && game->current_score == game->score)
	{
		printf("You win!\n");
		game->gameover = 1;
		mlx_close_window(game->mlx);
		return;
	}
	else if (game->map[y][x] == '0')
		update_map_and_images(x, y, game);
	else if (game->map[y][x] == 'C')
	{
		update_map_and_images(x, y, game);
		game->current_score++;
		i = 0;
		while (i < game->collectible->count)
		{
			if (game->collectible->instances[i].x == x * TILE_SIZE &&
				game->collectible->instances[i].y == y * TILE_SIZE)
			{
				game->collectible->instances[i].enabled = false;
				break;
			}
			i++;
		}
	}
	game->player_x = x;
	game->player_y = y;
	game->steps++;
	printf("Steps: %d\n", game->steps);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)param;
	x = game->player_x;
	y = game->player_y;
	if (game->gameover)
		return;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		handle_move(x, y - 1, game);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		handle_move(x, y + 1, game);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		handle_move(x - 1, y, game);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		handle_move(x + 1, y, game);
}
