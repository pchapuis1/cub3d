/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:14:55 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/23 13:44:38 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static int	start_map(char *file)
{
	int	i;
	int	status;
	int	count;

	i = 0;
	status = 0;
	count = 0;
	while (file[i] && count < 6)
	{
		if (status == 1 && file[i] != '\n')
			count ++;
		if (file[i] == '\n')
			status = 1;
		else
			status = 0;
		i ++;
	}
	while (file[i] && file[i] == '\n')
		i ++;
	return (i);
}

int	is_map_split(char *file)
{
	int	i;
	int	status;
	int	error;

	i = start_map(file);
	status = 0;
	error = 0;
	while (file[i])
	{
		if (status == 1 && file[i] == '\n')
			error = 1;
		if (file[i] == '\n')
			status = 1;
		else
			status = 0;
		if (error == 1 && file[i] != '\n')
			return (1);
		i ++;
	}
	return (0);
}
