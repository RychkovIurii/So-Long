/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:35:03 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/14 16:45:58 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static mlx_image_t	*b_load_image(t_game *game, mlx_t *mlx, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		b_show_error(game, "Failed to load texture");
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		b_show_error(game, "Failed to create image");
	if (image->width != TILE_SIZE || image->height != TILE_SIZE)
		if (!mlx_resize_image(image, TILE_SIZE, TILE_SIZE))
			b_show_error(game, "Failed to resize image");
	return (image);
}

void	b_load_images(t_game *game)
{
	game->player = b_load_image(game, game->mlx, "textures/player.png");
	game->wall = b_load_image(game, game->mlx, "textures/wall.png");
	game->floor = b_load_image(game, game->mlx, "textures/floor.png");
	game->collectible = b_load_image(game,
			game->mlx, "textures/collectible.png");
	game->exit_img = b_load_image(game, game->mlx, "textures/exit.png");
	game->enemy = b_load_image(game, game->mlx, "bonus/enemy.png");
}
