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

static void	b_count_tile_size(t_game *game)
{
	float	tile_w;
	float	tile_h;
	float	min_size;

	tile_w = SCREEN_W / game->map_width;
	tile_h = SCREEN_H / game->map_height;
	min_size = TILE_SIZE * MIN_SCALE;
	if (tile_w < min_size || tile_h < min_size)
		b_show_error(game, "Map is too big, try to pass smaller map");
	if (tile_h > tile_w)
		game->tilesize = tile_w;
	else
		game->tilesize = tile_h;
}

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
	if (image->width != (uint32_t)game->tilesize
		|| image->height != (uint32_t)game->tilesize)
		if (!mlx_resize_image(image, game->tilesize, game->tilesize))
			b_show_error(game, "Failed to resize image");
	return (image);
}

void	b_load_images(t_game *game)
{
	b_count_tile_size(game);
	game->mlx = mlx_init(game->map_width * game->tilesize,
			game->map_height * game->tilesize, "So Long", true);
	if (!game->mlx)
		b_show_error(game, "Init error");
	game->player = b_load_image(game, game->mlx, "textures/player.png");
	game->wall = b_load_image(game, game->mlx, "textures/wall.png");
	game->floor = b_load_image(game, game->mlx, "textures/floor.png");
	game->collectible = b_load_image(game,
			game->mlx, "textures/collectible.png");
	game->exit_img = b_load_image(game, game->mlx, "textures/exit.png");
	game->enemy = b_load_image(game, game->mlx, "bonus/enemy.png");
	game->enemy1 = b_load_image(game, game->mlx, "bonus/enemy1.png");
	game->enemy2 = b_load_image(game, game->mlx, "bonus/enemy2.png");
}
