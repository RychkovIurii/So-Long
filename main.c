/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:36:12 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/07 17:19:13 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

void	my_keyhook(mlx_key_data_t keydata, void	*param)
{
	t_game	*game;


	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	else
		handle_input(game, keydata.key);
}

void	load_map(char *filename, t_game *game)
{
	int		fd;
	char	*mapline;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		//some error handler
		return ;
	}
	mapline = 
	close(fd);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	init_game(&game);
	load_map(argv[1], &game); // get_next_line
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_loop(game.mlx);

	mlx_terminate(game.mlx);
	return (0);
}

/* #include "MLX42/MLX42.h"
#include <stdlib.h>
#include <string.h>
#define BPP sizeof(int32_t)

int32_t	main(void)
{
    mlx_t* mlx = mlx_init(256, 256, "MLX42", true);
    if (!mlx)
        exit(EXIT_FAILURE);

    mlx_image_t* img = mlx_new_image(mlx, 128, 128); //Создает новое изображение размером 128x128 пикселей

    // Set the channels of each pixel in our image to the maximum byte value of 255. 
    memset(img->pixels, 255, img->width * img->height * BPP);

    mlx_image_to_window(mlx, img, 0, 0); //Отображает изображение в окне на позиции (0, 0).

    // Run the main loop and terminate on quit.  
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
} */
