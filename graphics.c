/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:35:03 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/11 09:29:58 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*load_image(mlx_t *mlx, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
	{
		fprintf(stderr, "Failed to load texture: %s\n", path);
		exit(1);
	}
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
	{
		fprintf(stderr, "Failed to create image from texture: %s\n", path);
		exit(1);
	}
	if (image->width != TILE_SIZE || image->height != TILE_SIZE)
	{
		if (!mlx_resize_image(image, TILE_SIZE, TILE_SIZE))
		{
			fprintf(stderr, "Failed to resize image: %s\n", path);
			exit(1);
		}
	}
	return (image);
}

void	load_images(t_game *game)
{
	game->player = load_image(game->mlx, "textures/player.png");
	game->wall = load_image(game->mlx, "textures/wall.png");
	game->floor = load_image(game->mlx, "textures/floor.png");
	game->collectible = load_image(game->mlx, "textures/collectible.png");
	game->exit_img = load_image(game->mlx, "textures/exit.png");
}
