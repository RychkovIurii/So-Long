/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:25:58 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/14 11:49:29 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup_game(t_game *game)
{
	size_t	i;

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
		if (game->player)
			mlx_delete_image(game->mlx, game->player);
		mlx_terminate(game->mlx);
		game->mlx = NULL;
	}
	i = 0;
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
		game->map = NULL;
	}
}

void	show_error(t_game *game, char *message)
{
	cleanup_game(game);
	ft_printf("Error\n%s\n", message);
	exit(1);
}

void	map_handler(t_game *game, char *filename)
{
	t_position	player_start;

	get_map_height(game, filename);
	load_map(game, filename);
	ft_check_chars(game);
	load_images(game);
	parse_map(game);
	ft_validate_walls(game);
	player_start = (t_position){game->player_x, game->player_y};
	if (!validate_path(game, player_start))
		show_error(game, "No valid path");
}
