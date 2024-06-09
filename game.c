/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:22:31 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/10 00:12:42 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprite_frames(t_game *game, t_sprite *sprite, const char *file_path, int frame_count)
{
	mlx_texture_t	*sprite_sheet = mlx_load_png(file_path);
	if (!sprite_sheet) {
		fprintf(stderr, "Failed to load sprite sheet: %s\n", file_path);
		exit(1);
	}

	sprite->frames = malloc(sizeof(mlx_image_t *) * frame_count);
	for (int i = 0; i < frame_count; ++i) {
		sprite->frames[i] = mlx_texture_to_image(game->mlx, sprite_sheet);
		if (!sprite->frames[i]) {
			fprintf(stderr, "Failed to create image from texture for frame %d\n", i);
			exit(1);
		}
	}

	sprite->frame_count = frame_count;
	sprite->width = FRAME_WIDTH;
	sprite->height = FRAME_HEIGHT;
	sprite->current_frame = 0;

	mlx_delete_texture(sprite_sheet); // Удаляем текстуру спрайт-листа
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init(960, 640, "So Long", true);
	if (!game->mlx) {
		fprintf(stderr, "MLX42 initialization failed\n");
		exit(1);
	}

	load_sprite_frames(game, &game->player_idle, "textures/player_idle.png", IDLE_FRAME_COUNT);
	load_sprite_frames(game, &game->player_run, "textures/player_run.png", RUN_FRAME_COUNT);
	load_sprite_frames(game, &game->collectible, "textures/collectible.png", COLLECTIBLE_FRAME_COUNT);

	game->wall.frames = malloc(sizeof(mlx_image_t *));
	game->wall.frames[0] = mlx_texture_to_image(game->mlx, mlx_load_png("textures/wall.png"));
	game->wall.frame_count = 1;
	game->wall.width = 32;
	game->wall.height = 32;
	game->wall.current_frame = 0;

	game->floor.frames = malloc(sizeof(mlx_image_t *));
	game->floor.frames[0] = mlx_texture_to_image(game->mlx, mlx_load_png("textures/floor.png"));
	game->floor.frame_count = 1;
	game->floor.width = 32;
	game->floor.height = 32;
	game->floor.current_frame = 0;

	game->exit.frames = malloc(sizeof(mlx_image_t *));
	game->exit.frames[0] = mlx_texture_to_image(game->mlx, mlx_load_png("textures/exit.png"));
	game->exit.frame_count = 1;
	game->exit.width = 32;
	game->exit.height = 32;
	game->exit.current_frame = 0;

	game->player_x = 0;
	game->player_y = 0;
	game->steps = 0; // Инициализация счетчика шагов
	game->is_running = false; // Изначально игрок не движется
}
