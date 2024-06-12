/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:25:58 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/12 18:03:34 by irychkov         ###   ########.fr       */
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
		i = 0;
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
		mlx_terminate(game->mlx);
	}
}

void	show_error(t_game *game, char *message)
{
	cleanup_game(game);
	printf("Error\n%s\n", message);
	exit(1);
}