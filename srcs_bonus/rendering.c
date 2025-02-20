/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:45:09 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/22 15:41:22 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	get_info_door(t_raycasting *ray, t_data *img, t_render *render)
{
	if (ray->side >= 2)
	{
		render->dst = (int *)img->map.door.addr;
		render->img_height = img->map.door.img_height;
		render->img_width = img->map.door.img_width;
	}
	if (ray->side == 4)
		ray->side = 0;
	if (ray->side == 5)
		ray->side = 1;
}

static void	get_info_texture(t_raycasting *ray, t_data *img, t_render *render)
{
	if (ray->side == 1 && ray->step_y == -1)
	{
		render->dst = (int *)img->map.north.addr;
		render->img_height = img->map.north.img_height;
		render->img_width = img->map.north.img_width;
	}
	else if (ray->side == 1)
	{
		render->dst = (int *)img->map.south.addr;
		render->img_height = img->map.south.img_height;
		render->img_width = img->map.south.img_width;
	}
	else if (ray->side == 0 && ray->step_x == -1)
	{
		render->dst = (int *)img->map.west.addr;
		render->img_height = img->map.west.img_height;
		render->img_width = img->map.west.img_width;
	}
	else
	{
		render->dst = (int *)img->map.east.addr;
		render->img_height = img->map.east.img_height;
		render->img_width = img->map.east.img_width;
	}
	get_info_door(ray, img, render);
}

void	print_texture(int x, t_render *render, t_data *img, t_raycasting ray)
{
	int			color;

	get_info_texture(&ray, img, render);
	if (ray.side % 2 != 0 && ray.step_y == 1)
		ray.wall_x = 1 - ray.wall_x;
	if (ray.side % 2 == 0 && ray.step_x == 1)
		ray.wall_x = 1 - ray.wall_x;
	while (x <= img->map.res_height && x <= render->ceiling)
	{
		color = ((int)(((1 - ((render->ceiling - x) \
			/ (render->ceiling - render->floor))) * render->img_height)) \
			*render->img_width + (int)(ray.wall_x * render->img_width));
		pixel_to_image(img, x, img->map.res_length - render->count,
			render->dst[color]);
		x ++;
	}
}
