/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:31:42 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/22 18:50:22 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static unsigned int	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

static int	number_here(char *line, int *i)
{
	int	tmp;
	int	status;

	tmp = *i;
	status = 0;
	while (line[tmp])
	{
		if (line[tmp] >= '0' && line[tmp] <= '9')
			status = 1;
		tmp ++;
	}
	if (status == 0)
		return (-1);
	return (0);
}

static int	get_rgb_values(char *id, char *line, int *i)
{
	int	value;
	int	init;

	init = *i;
	while (line[*i] && line[*i] == ' ')
		*i += 1;
	if (line[*i] && ((!init && line[*i] == id[0]) || line[*i] == ','))
		*i += 1;
	if (number_here(line, i) == -1)
		return (-1);
	value = ft_atoi(&line[*i]);
	while (line[*i] && line[*i] == ' ')
		*i += 1;
	while (line[*i] && line[*i] >= '0' && line[*i] <= '9')
		*i += 1;
	if (value >= 0 && value <= 255)
		return (value);
	return (-1);
}

int	get_color(char *id, char *line, t_data *img)
{
	int	value_r;
	int	value_g;
	int	value_b;
	int	i;

	if (!ft_strcmp(id, "C") || !ft_strcmp(id, "F"))
	{
		i = 0;
		value_r = get_rgb_values(id, line, &i);
		value_g = get_rgb_values(id, line, &i);
		value_b = get_rgb_values(id, line, &i);
		i--;
		while (line[++i])
			if (line[i] != ' ' && line[i] != '\n')
				return (error_config('F'), 1);
		if (value_r < 0 || value_g < 0 || value_b < 0)
			return (error_config('E'), 1);
		if (id[0] == 'C')
			img->map.ceiling_color = create_rgb(value_r, value_g, value_b);
		else
			img->map.floor_color = create_rgb(value_r, value_g, value_b);
	}
	return (0);
}
