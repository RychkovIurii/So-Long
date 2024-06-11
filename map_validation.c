/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:18:23 by irychkov          #+#    #+#             */
/*   Updated: 2024/06/11 07:49:34 by irychkov         ###   ########.fr       */
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
