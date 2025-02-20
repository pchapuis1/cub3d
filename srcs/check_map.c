/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:06:47 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/19 13:29:07 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_arg(char **map, char c)
{
	int		nb;
	size_t	width;
	int		length;

	nb = 0;
	length = 0;
	while (map[length] != NULL)
	{
		width = 0;
		while (width < ft_strlen(map[length]))
		{
			if (map[length][width] == c)
				nb ++;
			width ++;
		}
		length ++;
	}
	return (nb);
}

static int	contact_void(t_map data)
{
	int	i;
	int	j;

	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == '0')
			{
				if (i + 1 >= data.height || i - 1 < 0
					|| j - 1 < 0 || j + 1 >= data.width)
					return (1);
			}
			j ++;
		}
		i ++;
	}
	return (0);
}

static int	check_close_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
			{
				if (((map[i + 1]) && (map[i + 1][j]) && map[i + 1][j] == '0'))
					return (1);
				if (((i - 1 >= 0) && (map[i - 1][j]) && map[i - 1][j] == '0'))
					return (1);
				if (((map[i][j + 1]) && map[i][j + 1] == '0'))
					return (1);
				if (((j - 1 >= 0) && (map[i][j - 1]) && map[i][j - 1] == '0'))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	unknown_arg(t_map data)
{
	size_t	width;
	int		length;

	length = 0;
	while (data.map[length] != NULL)
	{
		width = 0;
		while (width < ft_strlen(data.map[length]))
		{
			if (data.map[length][width] != data.empty
				&& !is_direction(data.map[length][width])
				&& data.map[length][width] != data.wall
				&& data.map[length][width] != ' ')
				return (1);
			width ++;
		}
		length ++;
	}
	return (0);
}

int	check_map(t_map data)
{
	if (count_arg(data.map, 'N') + count_arg(data.map, 'S')
		+ count_arg(data.map, 'E') + count_arg(data.map, 'W') != 1)
		return (error_config('C'));
	if (contact_void(data) == 1 || check_close_map(data.map) == 1)
		return (error_config('W'));
	if (unknown_arg(data) == 1)
		return (error_config('A'));
	return (0);
}
