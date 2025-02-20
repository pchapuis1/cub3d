/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:54:23 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/23 13:43:56 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	door_valid(t_map data)
{
	int	i;
	int	j;

	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == 'D')
			{
				if ((data.map[i + 1][j] != '1' || data.map[i - 1][j] != '1') \
					&& (data.map[i][j + 1] != '1' || data.map[i][j - 1] != '1'))
					return (1);
			}
			j ++;
		}
		i ++;
	}
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
	while (file[i] && count < 7)
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
