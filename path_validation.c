/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:28:09 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/12 21:44:12 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**create_temp_map(t_game *game)
{
	size_t		i;
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

static int	explore_path(t_game *game,char **temp_map, t_position position)
{
	static int	collect = 0;
	static int	exit_found = 0;

	if (temp_map[position.y][position.x] == '1')
		return (0);
	else if (temp_map[position.y][position.x] == 'C')
		collect++;
	else if (temp_map[position.y][position.x] == 'E')
		exit_found = 1;
	temp_map[position.y][position.x] = '1';
	explore_path(game, temp_map, (t_position){position.x + 1, position.y});
	explore_path(game, temp_map, (t_position){position.x - 1, position.y});
	explore_path(game, temp_map, (t_position){position.x, position.y + 1});
	explore_path(game, temp_map, (t_position){position.x, position.y - 1});
	if (collect == game->collectibles && exit_found)
		return (1);
	return (0);
}

int	validate_path(t_game *game, t_position position)
{
	int		result;
	char	**temp;

	temp = create_temp_map(game);
	if (!temp)
		return (0);	//not sure what type of errors
	result = explore_path(game, temp, position);
	for (size_t i = 0; i < game->map_height; i++)
		free(temp[i]);
	free(temp);
	return (result);
}
