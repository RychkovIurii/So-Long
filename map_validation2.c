/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:54:26 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/11 12:12:49 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_validate_file_ext(char *filename)
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

static void	check_one_char(char c, int *exits, int *players, int *collectibles)
{
	if (c == 'E')
		*exits += 1;
	else if (c == 'P')
		*players += 1;
	else if (c == 'C')
		*collectibles += 1;
}

static int	ft_check_chars(t_game *game)
{
	size_t	h;
	size_t	w;
	int		exits;
	int		players;
	int		collectibles;

	h = 0;
	exits = 0;
	players = 0;
	collectibles = 0;
	while (h < game->map_height)
	{
		w = 0;
		while (game->map[h][w] != '\n' && game->map[h][w] != '\0')
		{
			if (ft_strchr("01CPE", game->map[h][w]) == NULL)
				return (0);
			check_one_char(game->map[h][w], &exits, &players, &collectibles);
			w++;
		}
		h++;
	}
	if (collectibles < 1 || players != 1 || exits != 1)
		return (0);
	return (1);
}
