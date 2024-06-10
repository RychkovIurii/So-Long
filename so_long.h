/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:14:20 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/10 23:08:37 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <MLX42/MLX42.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

#define TILE_SIZE 32

typedef struct	s_game {
	mlx_t		*mlx;
	mlx_image_t	*player;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*collectible;
	mlx_image_t	*exit_img;
	int			player_x;
	int			player_y;
	int			score;
	int			current_score;
	char		**map;
	int			map_width;
	int			map_height;
	int			steps;
	int			gameover;
} t_game;

mlx_image_t	*load_image(mlx_t *mlx, const char *path);
void		load_images(t_game *game);
void		add_instance(mlx_t *mlx, mlx_image_t *img, int x, int y);
void		my_keyhook(mlx_key_data_t keydata, void *param);

#endif
