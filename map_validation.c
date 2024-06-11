/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:18:23 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/11 11:13:57 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	ft_validate_side_walls(t_game *game)
{
	int	h;

	h = 1;
	while (h < game->map_height)
	{
		if (game->map[h][0] != '1')
			return (0);
		else if (game->map[h][game->map_width - 1] != '1')
			return (0);
		h += 1;
	}
	return (1);
}

static int	ft_valid_top_wall(t_game *game)
{
	int	w;

	w = 0;
	while (w < game->map_width)
	{
		if (game->map[0][w] != '1')
			return (0);
		w += 1;
	}
	return (1);
}

static int	ft_valid_bottom_wall(t_game *game)
{
	int	w;

	w = 0;
	while (w < game->map_width)
	{
		if (game->map[game->map_height - 1][w] != '1')
			return (0);
		w += 1;
	}
	return (1);
}

static int	ft_check_chars(t_game *game)
{
	int	h;
	int	w;
	int	exits;
	int	players;
	int	collectibles;

	h = 0;
	exits = 0;
	players = 0;
	collectibles = 0;
	while (h < game->height)
	{
		w = 0;
		while (game->map[h][w] != '\n' && game->map[h][w] != '\0')
		{
			if (ft_strchr(const char *s, int c) == NULL)
				return (0);
			if (game->map[h][w] == 'E')
				exits += 1;
			else if (game->map[h][w] == 'P')
				players += 1;
			else if (game->map[h][w] == 'C')
				collectibles += 1;
			w++;
		}
		h++;
	}
	if (collectibles < 1 || players != 1 || exits != 1)
		return (0);
	return (1);
}


//The map must be rectangular.
//Empty space in the middle.
//You have to check if there’s a valid path in the map.
//If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way, and return "Error\n" followed by an explicit error message of your choice.