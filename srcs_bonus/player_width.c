/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:27:23 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/21 19:36:43 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	position_valid_angle(t_data *img, float player_w)
{
	t_map	*m;

	m = &img->map;
	if (m->map[(int)floor(m->y + player_w)][(int)floor(m->x + player_w)] != '0'
		&& m->map[(int)floor(m->y + player_w)] \
			[(int)floor(m->x + player_w)] != 'd')
		return (1);
	if (m->map[(int)floor(m->y - player_w)][(int)floor(m->x + player_w)] != '0'
		&& m->map[(int)floor(m->y - player_w)] \
			[(int)floor(m->x + player_w)] != 'd')
		return (1);
	if (m->map[(int)floor(m->y + player_w)][(int)floor(m->x - player_w)] != '0'
		&& m->map[(int)floor(m->y + player_w)] \
			[(int)floor(m->x - player_w)] != 'd')
		return (1);
	if (m->map[(int)floor(m->y - player_w)][(int)floor(m->x - player_w)] != '0'
		&& m->map[(int)floor(m->y - player_w)] \
			[(int)floor(m->x - player_w)] != 'd')
		return (1);
	return (0);
}

int	position_valid(t_data *img)
{
	float	player_w;
	t_map	*m;

	m = &img->map;
	player_w = 0.1;
	if (m->map[(int)floor(m->y + player_w)][(int)m->x] != '0'
		&& m->map[(int)floor(m->y + player_w)][(int)m->x] != 'd')
		return (1);
	if (m->map[(int)floor(m->y - player_w)][(int)m->x] != '0'
		&& m->map[(int)floor(m->y - player_w)][(int)m->x] != 'd')
		return (1);
	if (m->map[(int)m->y][(int)floor(m->x + player_w)] != '0'
		&& m->map[(int)m->y][(int)floor(m->x + player_w)] != 'd')
		return (1);
	if (m->map[(int)m->y][(int)floor(m->x - player_w)] != '0'
		&& m->map[(int)m->y][(int)floor(m->x - player_w)] != 'd')
		return (1);
	return (position_valid_angle(img, player_w));
}
