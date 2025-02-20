/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:21:08 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/23 12:53:32 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	free_copy(char **cp_map, int i)
{
	while (i > -1)
	{
		free(cp_map[i]);
		i --;
	}
	free(cp_map);
}

static int	fill_map(t_data *img, char **file, int start, size_t max)
{
	int		i;
	size_t	size;

	i = 0;
	while (file[i + start])
	{
		img->map.map[i] = malloc(sizeof(char) * max + 1);
		if (!img->map.map[i])
			return (free_copy(img->map.map, i - 1), -1);
		size = ft_strlen(file[start + i]);
		ft_strlcpy(img->map.map[i], file[start + i], size + 1);
		while (size < max)
		{
			img->map.map[i][size] = ' ';
			size ++;
		}
		img->map.map[i][size] = '\0';
		i ++;
	}
	return (i);
}

int	set_path_door(char *line, int direction, t_data *img)
{
	if (direction == DOOR && img->map.status_path_door != 1)
	{
		img->map.path_door = last_word(line);
		img->map.status_path_door = 1;
		return (0);
	}
	return (1);
}

int	is_void(char **map, int i, int j)
{
	if (map[i][j] == '0' || map[i][j] == 'D')
		return (1);
	return (0);
}

int	parsing_map(char **file, t_data *img, int start)
{
	int		i;
	size_t	max;

	i = start;
	max = ft_strlen(file[i]) + 1;
	while (file[i])
	{
		if (max < ft_strlen(file[i]))
			max = ft_strlen(file[i]);
		i ++;
	}
	i = i - start + 1;
	img->map.map = malloc(sizeof(char *) * i);
	if (!img->map.map)
		return (1);
	i = fill_map(img, file, start, max);
	if (i < 0)
		return (1);
	img->map.map[i] = NULL;
	return (0);
}
