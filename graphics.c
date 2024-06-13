/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:35:03 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/13 13:23:05 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*load_image(t_game *game, mlx_t *mlx, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		show_error(game, "Failed to load texture");
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		show_error(game, "Failed to create image");
	if (image->width != TILE_SIZE || image->height != TILE_SIZE)
		if (!mlx_resize_image(image, TILE_SIZE, TILE_SIZE))
			show_error(game, "Failed to resize image");
	return (image);
}

void	load_images(t_game *game)
{
	game->player = load_image(game, game->mlx, "textures/player.png");
	game->wall = load_image(game, game->mlx, "textures/wall.png");
	game->floor = load_image(game, game->mlx, "textures/floor.png");
	game->collectible = load_image(game, game->mlx, "textures/collectible.png");
	game->exit_img = load_image(game, game->mlx, "textures/exit.png");
}
