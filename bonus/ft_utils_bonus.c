/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:25:58 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/14 16:28:35 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	cleanup_imgs(t_game *game)
{
	if (game->mlx)
	{
		if (game->wall)
			mlx_delete_image(game->mlx, game->wall);
		if (game->floor)
			mlx_delete_image(game->mlx, game->floor);
		if (game->collectible)
			mlx_delete_image(game->mlx, game->collectible);
		if (game->exit_img)
			mlx_delete_image(game->mlx, game->exit_img);
		if (game->enemy)
			mlx_delete_image(game->mlx, game->enemy);
		if (game->enemy1)
			mlx_delete_image(game->mlx, game->enemy1);
		if (game->enemy2)
			mlx_delete_image(game->mlx, game->enemy2);
		if (game->player)
			mlx_delete_image(game->mlx, game->player);
		mlx_terminate(game->mlx);
	}
}

void	b_cleanup_game(t_game *game)
{
	size_t	i;

	i = 0;
	cleanup_imgs(game);
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
}

void	b_show_error(t_game *game, char *message)
{
	b_cleanup_game(game);
	ft_printf("Error\n%s\n", message);
	exit(1);
}

void	b_map_handler(t_game *game, char *filename)
{
	t_position	player_start;

	b_get_map_height(game, filename);
	b_load_map(game, filename);
	b_ft_check_chars(game);
	b_load_images(game);
	b_parse_map(game);
	b_ft_validate_walls(game);
	player_start = (t_position){game->player_x, game->player_y};
	if (!b_validate_path(game, player_start))
		b_show_error(game, "No valid path");
}

void	anim_blackhole(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemies)
	{
		if (game->enemy->instances[i].enabled == true)
		{
			game->enemy->instances[i].enabled = false;
			game->enemy1->instances[i].enabled = false;
			game->enemy2->instances[i].enabled = true;
		}
		else if (game->enemy2->instances[i].enabled == true)
		{
			game->enemy->instances[i].enabled = false;
			game->enemy1->instances[i].enabled = true;
			game->enemy2->instances[i].enabled = false;
		}
		else
		{
			game->enemy->instances[i].enabled = true;
			game->enemy1->instances[i].enabled = false;
			game->enemy2->instances[i].enabled = false;
		}
		i++;
	}
}
