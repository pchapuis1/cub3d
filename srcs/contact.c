/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:39:07 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/23 14:18:59 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_raycasting	find_first(float x, float y, t_data *img, t_pos delta)
{
	t_raycasting	raycast;

	if (x > 0)
	{
		raycast.dist_x = ((int)img->map.x + 1 - img->map.x) * delta.x;
		raycast.step_x = 1;
	}
	else
	{
		raycast.dist_x = (img->map.x - (int)img->map.x) * delta.x;
		raycast.step_x = -1;
	}
	if (y > 0)
	{
		raycast.dist_y = (img->map.y - (int)img->map.y) * delta.y;
		raycast.step_y = -1;
	}
	else
	{
		raycast.dist_y = ((int)img->map.y + 1 - img->map.y) * delta.y;
		raycast.step_y = 1;
	}
	return (raycast);
}

void	find_delta(t_pos *delta, float dir_x, float dir_y)
{
	delta->x = 1000000000;
	delta->y = 1000000000;
	if (dir_x > 0.000001 || dir_x < -0.000001)
		delta->x = fabs(1 / dir_x);
	if (dir_y > 0.000001 || dir_y < -0.000001)
		delta->y = fabs(1 / dir_y);
}

void	find_contact(t_raycasting *ray, t_pos delta,
	t_data *img, t_pos_int *pos)
{
	int			contact;

	contact = 0;
	while (contact != 1)
	{
		if (ray->dist_x < ray->dist_y)
		{
			pos->x += ray->step_x;
			ray->dist_x += delta.x;
			ray->side = 0;
		}
		else
		{
			pos->y += ray->step_y;
			ray->dist_y += delta.y;
			ray->side = 1;
		}
		if (img->map.map[pos->y][pos->x] == '1')
			contact = 1;
	}
}
