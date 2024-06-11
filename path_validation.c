/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:28:09 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/11 14:53:15 by irychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_queue(t_queue *q, int capacity)
{
	q->capacity = capacity;
	q->items = malloc(sizeof(t_position) * capacity);
	q->front = 0;
	q->rear = 0;
	q->size = 0;
}

int	enqueue(t_queue *q, t_position item)
{
	if (q->size >= q->capacity)
		return (0);
	q->items[q->rear] = item;
	q->rear = (q->rear + 1) % q->capacity;
	q->size++;
	return (1);
}

t_position	dequeue(t_queue *q)
{
	t_position	item;

	item = {0, 0};
	if (q->size == 0)
		return (item);
	item = q->items[q->front];
	q->front = (q->front + 1) % q->capacity;
	q->size--;
	return (item);
}

int	is_queue_empty(t_queue *q)
{
	if (q->size == 0)
		return (1);
	return (0);
}

int	bfs_validate_path(t_game *game, t_position start)
{
	t_queue		queue;
	t_position	current;
	int			collected_count;
	int			marked[game->map_height][game->map_width];
	int			directions[4][2];

	collected_count = 0;
	init_queue(&queue, game->map_width * game->map_height);
	ft_memset(marked, 0, sizeof(marked));
	enqueue(&queue, start);
	marked[start.y][start.x] = 1;
	while (!is_queue_empty(&queue))
	{
		current = dequeue(&queue);
		directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		int i = 0;
		
		while (i < 4)
		{
			int new_x = current.x + directions[i][0];
			int new_y = current.y + directions[i][1];

			if (new_x >= 0 && new_x < game->map_width && new_y >= 0
				&& new_y < game->map_height && !marked[new_y][new_x]
				&& game->map[new_y][new_x] != '1')
			{
				marked[new_y][new_x] = 1;
				if (game->map[new_y][new_x] == 'C')
					collected_count++;
				if (game->map[new_y][new_x] == 'E' &&
					collected_count == game->collectibles)
				{
					free(queue.items);
					return (1);
				}
				enqueue(&queue, (t_position){new_x, new_y});
			}
			i++;
		}
	}

	free(queue.items);
	return (0);
}
