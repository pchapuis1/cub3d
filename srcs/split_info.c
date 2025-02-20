/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:14:55 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/23 15:21:47 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]
			&& s1[i] && s2[i])
	{
		i ++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

static int	set_path(char *line, int direction, t_data *img)
{
	if (direction == NORTH && img->map.status_path_wall_north != 1)
	{
		img->map.path_wall_north = last_word(line);
		img->map.status_path_wall_north = 1;
	}
	else if (direction == SOUTH && img->map.status_path_wall_south != 1)
	{
		img->map.path_wall_south = last_word(line);
		img->map.status_path_wall_south = 1;
	}
	else if (direction == WEST && img->map.status_path_wall_west != 1)
	{
		img->map.path_wall_west = last_word(line);
		img->map.status_path_wall_west = 1;
	}
	else if (direction == EAST && img->map.status_path_wall_east != 1)
	{
		img->map.path_wall_east = last_word(line);
		img->map.status_path_wall_east = 1;
	}
	else
		return (1);
	return (0);
}

static int	get_info(char *id, char *line, t_data *img)
{
	if (!ft_strcmp(id, "F") || !ft_strcmp(id, "C"))
		return (get_color(id, line, img));
	if (count_word(line) != 2)
		return (error_config('F'), 1);
	if (!ft_strcmp(id, "NO"))
		if (set_path(line, NORTH, img))
			return (error_config('D'), 1);
	if (!ft_strcmp(id, "SO"))
		if (set_path(line, SOUTH, img))
			return (error_config('D'), 1);
	if (!ft_strcmp(id, "WE"))
		if (set_path(line, WEST, img))
			return (error_config('D'), 1);
	if (!ft_strcmp(id, "EA"))
		if (set_path(line, EAST, img))
			return (error_config('D'), 1);
	return (0);
}

static int	is_valid_id(char *id)
{
	return (!ft_strcmp(id, "NO") || !ft_strcmp(id, "SO") || !ft_strcmp(id, "WE")
		|| !ft_strcmp(id, "EA")
		|| !ft_strcmp(id, "F") || !ft_strcmp(id, "C"));
}

int	split_info(char **file, t_data *img)
{
	int		i;
	char	*id;
	int		return_value;

	i = -1;
	img->map.map = NULL;
	while (file[++i])
	{
		id = first_word(file[i]);
		if (!is_valid_id(id))
		{
			free(id);
			if (i != 6)
				return (ft_free(file), error_config('I'));
			return (parsing_map(file, img, i));
		}
		return_value = get_info(id, file[i], img);
		free(id);
		if (return_value != 0)
			return (ft_free(file), return_value);
	}
	if (!img->map.map)
		return (ft_free(file), error_config('V'), 1);
	return (0);
}
