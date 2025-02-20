/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:47:36 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/19 13:56:49 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_position_valid(t_data *img)
{
	if (img->map.y + 1 >= img->map.height || img->map.y - 1 < 0
		|| img->map.x - 1 < 0 || img->map.x + 1 >= img->map.width)
		return (ft_free(img->map.map), error_config('P'), 1);
	if (img->map.map[(int)(img->map.y) + 1][(int)(img->map.x)] == ' ')
		return (ft_free(img->map.map), error_config('P'), 1);
	if (img->map.map[(int)(img->map.y) - 1][(int)(img->map.x)] == ' ')
		return (ft_free(img->map.map), error_config('P'), 1);
	if (img->map.map[(int)(img->map.y)][(int)(img->map.x) + 1] == ' ')
		return (ft_free(img->map.map), error_config('P'), 1);
	if (img->map.map[(int)(img->map.y)][(int)(img->map.x) - 1] == ' ')
		return (ft_free(img->map.map), error_config('P'), 1);
	return (0);
}

int	is_direction(int c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static float	find_degree(int c)
{
	int	degree;

	degree = c - 'E';
	if (degree % 9)
		degree = 270;
	else
		degree *= 10;
	return (degree);
}

int	find_player_position(t_data *img)
{
	int		height;
	int		width;
	float	*degree;

	height = -1;
	degree = &img->map.orientation.degree;
	while (img->map.map[++height])
	{
		width = -1;
		while (img->map.map[height][++width])
		{
			if (is_direction(img->map.map[height][width]))
			{
				img->map.x = width + 0.5;
				img->map.y = height + 0.5;
				*degree = find_degree(img->map.map[height][width]);
				img->map.map[height][width] = '0';
			}
		}
	}
	img->map.orientation.x = cosf(img->map.orientation.degree * RAD_CONV);
	img->map.orientation.y = sinf(img->map.orientation.degree * RAD_CONV);
	return (is_position_valid(img));
}
