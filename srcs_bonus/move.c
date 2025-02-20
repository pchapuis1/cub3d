/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:39:11 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/22 17:24:42 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
