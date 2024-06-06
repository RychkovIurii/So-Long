/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:14:20 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/06 23:34:11 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <MLX42/MLX42.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_sprite {
	mlx_image_t *img;
	int width;
	int height;
} t_sprite;

typedef struct s_game {
	mlx_t *mlx;
	t_sprite player;
	t_sprite wall;
	t_sprite floor;
	t_sprite collectible;
	t_sprite exit;
	int player_x;
	int player_y;
} t_game;

#endif
