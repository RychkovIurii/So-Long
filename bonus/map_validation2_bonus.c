/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:54:26 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/14 16:28:04 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	b_ft_validate_file_ext(char *filename)
{
	char	*ext;

	ext = NULL;
	ext = ft_strrchr(filename, '.');
	if (ext == NULL)
		return (0);
	if ((ft_strncmp(".ber\0", ext, 5)) == 0)
		return (1);
	return (0);
}

static void	b_check_one_char(char c, t_game *game)
{
	if (c == 'E')
		game->exits += 1;
	else if (c == 'P')
		game->players += 1;
	else if (c == 'C')
		game->collectibles += 1;
	else if (c == '!')
		game->enemies += 1;
}

void	b_ft_check_chars(t_game *game)
{
	size_t	h;
	size_t	w;

	h = 0;
	while (h < game->map_height)
	{
		w = 0;
		while (game->map[h][w] != '\0')
		{
			if (ft_strchr("01CPE!", game->map[h][w]) == NULL)
				b_show_error(game, "Map contains invalid char");
			b_check_one_char(game->map[h][w], game);
			w++;
		}
		h++;
	}
	if (game->collectibles < 1)
		b_show_error(game, "Map doesn't have Collectibles");
	else if (game->players != 1)
		b_show_error(game, "Should be one player on the map");
	else if (game->exits != 1)
		b_show_error(game, "Should be one exit on the map");
	else if (game->enemies == 0)
		b_show_error(game, "There are no enemies!");
}
