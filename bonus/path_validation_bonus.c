/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:28:09 by irychkov          #+#    #+#             */
/*   Updated: 2024/07/18 10:20:33 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	**b_create_temp_map(t_game *game)
{
	size_t	i;
	char	**temp_map;

	temp_map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!temp_map)
		return (NULL);
	i = 0;
	while (i < game->map_height)
	{
		temp_map[i] = ft_strdup(game->map[i]);
		if (!temp_map[i])
		{
			while (i > 0)
			{
				free(temp_map[i - 1]);
				i--;
			}
			free(temp_map);
			return (NULL);
		}
		i++;
	}
	temp_map[game->map_height] = NULL;
	return (temp_map);
}

static int	b_explore_path(t_game *game, char **temp_map, t_position position)
{
	static int	collect = 0;
	static int	exit_found = 0;

	if (temp_map[position.y][position.x] == '1')
		return (0);
	else if (temp_map[position.y][position.x] == '!')
		return (0);
	else if (temp_map[position.y][position.x] == 'C')
		collect++;
	else if (temp_map[position.y][position.x] == 'E')
	{
		exit_found = 1;
		return (0);
	}
	temp_map[position.y][position.x] = '1';
	b_explore_path(game, temp_map, (t_position){position.x + 1, position.y});
	b_explore_path(game, temp_map, (t_position){position.x - 1, position.y});
	b_explore_path(game, temp_map, (t_position){position.x, position.y + 1});
	b_explore_path(game, temp_map, (t_position){position.x, position.y - 1});
	if (collect == game->collectibles && exit_found)
		return (1);
	return (0);
}

int	b_validate_path(t_game *game, t_position position)
{
	int		result;
	size_t	i;
	char	**temp;

	temp = b_create_temp_map(game);
	if (!temp)
		b_show_error(game, "Memory allocation error");
	result = b_explore_path(game, temp, position);
	i = 0;
	while (i < game->map_height)
		free(temp[i++]);
	free(temp);
	return (result);
}
