/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:52:16 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/14 16:28:39 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	b_update_map_and_images(int x, int y, t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[y][x] = 'P';
	game->player->instances[0].x = x * TILE_SIZE;
	game->player->instances[0].y = y * TILE_SIZE;
}

static void	b_collect_item(t_game *game, int x, int y)
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

static int	b_check_game_end_conditions(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->current_score != game->collectibles)
		{
			ft_printf("Collect all items first!\n");
			return (0);
		}
		else
		{
			ft_printf("You win!\n");
			game->gameover = 1;
			mlx_close_window(game->mlx);
		}
	}
	return (1);
}

static void	b_handle_move(int x, int y, t_game *game)
{
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == '!')
	{
		ft_printf("You lose! Don't touch an enemy patrol\n");
		game->gameover = 1;
		mlx_close_window(game->mlx);
	}
	if (!b_check_game_end_conditions(game, x, y))
		return ;
	if (game->map[y][x] == '0')
		b_update_map_and_images(x, y, game);
	else if (game->map[y][x] == 'C')
	{
		b_update_map_and_images(x, y, game);
		b_collect_item(game, x, y);
	}
	game->player_x = x;
	game->player_y = y;
	game->steps++;
	ft_printf("Steps: %d\n", game->steps);
}

void	b_my_keyhook(mlx_key_data_t keydata, void *param)
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
		b_handle_move(x, y - 1, game);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		b_handle_move(x, y + 1, game);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		b_handle_move(x - 1, y, game);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		b_handle_move(x + 1, y, game);
}
