/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:18:23 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/11 12:56:53 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_validate_side_walls(t_game *game)
{
	size_t	h;

	h = 1;
	while (h < game->map_height)
	{
		if (game->map[h][0] != '1')
			return (0);
		else if (game->map[h][game->map_width - 1] != '1')
			return (0);
		h++;
	}
	return (1);
}

static int	ft_valid_top_wall(t_game *game)
{
	size_t	w;

	w = 0;
	while (w < game->map_width)
	{
		if (game->map[0][w] != '1')
			return (0);
		w++;
	}
	return (1);
}

static int	ft_valid_bottom_wall(t_game *game)
{
	size_t	w;

	w = 0;
	while (w < game->map_width)
	{
		if (game->map[game->map_height - 1][w] != '1')
			return (0);
		w++;
	}
	return (1);
}

static int	ft_validate_rectangle(t_game *game)
{
	size_t	h;
	size_t	w;
	size_t	len;

	h = 0;
	len = ft_strlen(game->map[0]);
	while (h < game->map_height)
	{
		if (len != (ft_strlen(game->map[h])))
			return (0);
		h++;
	}
	return (1);
}

int	ft_validate_walls(t_game *game)
{
	if (!ft_validate_rectangle(game))
		return (0);
	if (!ft_validate_side_walls(game))
		return (0);
	else if (!ft_valid_top_wall(game) || !ft_valid_bottom_wall(game))
		return (0);
	return (1);
}
