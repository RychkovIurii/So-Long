/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:44:43 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/11 15:18:28 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	bfs_validate_path(t_game *game, t_position start)
{
	t_queue	queue;
	int		collected_count;
	int		marked[game->map_height][game->map_width];

	collected_count = 0;
	init_queue(&queue, game->map_width * game->map_height);
	ft_memset(marked, 0, sizeof(marked));
	enqueue(&queue, start);
	marked[start.y][start.x] = 1;
	while (!is_queue_empty(&queue))
	{
		if (process_adjacent_nodes(&queue, game, marked, &collected_count))
		{
			free_queue(&queue);
			return (1);
		}
	}

	free_queue(&queue);
	return (0);
}

int	process_adjacent_nodes(t_queue *queue, t_game *game,
					int marked[][game->map_width], int *collected_count)
{
	int			i;
	int			new_x;
	int			new_y;
	int			directions[4][2];
	t_position	current;

	current = dequeue(queue);
	directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	i = 0;
	while (i < 4)
	{
		new_x = current.x + directions[i][0];
		new_y = current.y + directions[i][1];
		if (validate_move(new_x, new_y, game, marked, collected_count))
		{
			if (game->map[new_y][new_x] == 'E' &&
					*collected_count == game->collectibles)
				return (1);
			enqueue(queue, (t_position){new_x, new_y});
			marked[new_y][new_x] = 1;
		}
		i++;
	}
	return (0);
}

int	validate_move(int x, int y, t_game *game, int marked[][game->map_width], int *collected_count)
{
	if (x >= 0 && x < game->map_width && y >= 0 && y < game->map_height
		&& !marked[y][x] && game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'C')
			(*collected_count)++;
		return (1);
	}
	return (0);
}

void	free_queue(t_queue *queue)
{
	free(queue->items);
}
