/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:39:11 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/21 19:26:26 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	position_valid(t_data *img)
{
	float	player_w;
	t_map	*m;

	m = &img->map;
	player_w = 0.1;
	if (m->map[(int)floor(m->y + player_w)][(int)m->x] != '0')
		return (1);
	if (m->map[(int)floor(m->y - player_w)][(int)m->x] != '0')
		return (1);
	if (m->map[(int)m->y][(int)floor(m->x + player_w)] != '0')
		return (1);
	if (m->map[(int)m->y][(int)floor(m->x - player_w)] != '0')
		return (1);
	if (m->map[(int)floor(m->y + player_w)][(int)floor(m->x + player_w)] != '0')
		return (1);
	if (m->map[(int)floor(m->y - player_w)][(int)floor(m->x + player_w)] != '0')
		return (1);
	if (m->map[(int)floor(m->y + player_w)][(int)floor(m->x - player_w)] != '0')
		return (1);
	if (m->map[(int)floor(m->y - player_w)][(int)floor(m->x - player_w)] != '0')
		return (1);
	return (0);
}

void	move_forward(t_data *img)
{
	float	x_start;
	float	y_start;

	x_start = img->map.x;
	y_start = img->map.y;
	img->map.x += (img->map.orientation.x * img->map.player_speed);
	if (position_valid(img) == 1)
		img->map.x = x_start;
	img->map.y -= (img->map.orientation.y * img->map.player_speed);
	if (position_valid(img) == 1)
		img->map.y = y_start;
}

void	move_back(t_data *img)
{
	float	x_start;
	float	y_start;	

	x_start = img->map.x;
	y_start = img->map.y;
	img->map.x -= (img->map.orientation.x * img->map.player_speed);
	if (position_valid(img) == 1)
		img->map.x = x_start;
	img->map.y += (img->map.orientation.y * img->map.player_speed);
	if (position_valid(img) == 1)
		img->map.y = y_start;
}

void	move_left(t_data *img)
{
	float	x_start;
	float	y_start;

	x_start = img->map.x;
	y_start = img->map.y;
	img->map.x -= (img->map.orientation.y * img->map.player_speed);
	if (position_valid(img) == 1)
		img->map.x = x_start;
	img->map.y -= (img->map.orientation.x * img->map.player_speed);
	if (position_valid(img) == 1)
		img->map.y = y_start;
}

void	move_right(t_data *img)
{
	float	x_start;
	float	y_start;

	x_start = img->map.x;
	y_start = img->map.y;
	img->map.x += (img->map.orientation.y * img->map.player_speed);
	if (position_valid(img) == 1)
		img->map.x = x_start;
	img->map.y += (img->map.orientation.x * img->map.player_speed);
	if (position_valid(img) == 1)
		img->map.y = y_start;
}
