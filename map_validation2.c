/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:54:26 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/12 16:04:38 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validate_file_ext(char *filename)
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

static void	check_one_char(char c, t_game *game)
{
	if (c == 'E')
		game->exits += 1;
	else if (c == 'P')
		game->players += 1;
	else if (c == 'C')
		game->collectibles += 1;
}

int	ft_check_chars(t_game *game)
{
	size_t	h;
	size_t	w;

	h = 0;
	game->exits = 0;
	game->players = 0;
	game->collectibles = 0;
	while (h < game->map_height)
	{
		w = 0;
		while (game->map[h][w] != '\n' && game->map[h][w] != '\0')
		{
			if (ft_strchr("01CPE", game->map[h][w]) == NULL)
				return (0);
			check_one_char(game->map[h][w], game);
			w++;
		}
		h++;
	}
	if (game->collectibles < 1 || game->players != 1 || game->exits != 1)
		return (0);
	return (1);
}
