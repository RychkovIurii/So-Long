/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:52:16 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/13 13:51:35 by irychkov         ###   ########.fr       */
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

static void	collect_item(t_game *game, int x, int y)
{
	size_t	i;

	i = 0;
	game->current_score++;
	while (i < game->collectible->count)
	{
		if (game->collectible->instances[i].x == x * TILE_SIZE
			&& game->collectible->instances[i].y == y * TILE_SIZE)
		{
			game->collectible->instances[i].enabled = false;
			break ;
		}
		i++;
	}
}

static void	check_game_end_conditions(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->current_score != game->score)
			ft_printf("Collect all items first!\n");
		else
		{
			ft_printf("You win!\n");
			game->gameover = 1;
			mlx_close_window(game->mlx);
		}
	}
}

static void	handle_move(int x, int y, t_game *game)
{
	if (game->map[y][x] == '1')
		return ;
	check_game_end_conditions(game, x, y);
	if (game->map[y][x] == '0')
		update_map_and_images(x, y, game);
	else if (game->map[y][x] == 'C')
	{
		update_map_and_images(x, y, game);
		collect_item(game, x, y);
	}
	game->player_x = x;
	game->player_y = y;
	game->steps++;
	ft_printf("Steps: %d\n", game->steps);
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
		return ;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		handle_move(x, y - 1, game);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		handle_move(x, y + 1, game);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		handle_move(x - 1, y, game);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		handle_move(x + 1, y, game);
}
