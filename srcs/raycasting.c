/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:51:44 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/23 15:44:06 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_raycasting	intersection(t_data *img, float dir_x, float dir_y)
{
	t_pos			delta;
	t_raycasting	ray;
	t_pos_int		pos;

	find_delta(&delta, dir_x, dir_y);
	ray = find_first(dir_x, dir_y, img, delta);
	pos.x = (int)img->map.x;
	pos.y = (int)img->map.y;
	find_contact(&ray, delta, img, &pos);
	if (ray.side == 0)
	{
		ray.distance = (pos.x - img->map.x + (1 - ray.step_x) * 0.5) / dir_x;
		ray.wall_x = -img->map.y + ray.distance * dir_y;
	}
	else
	{
		ray.distance = (pos.y - img->map.y + (1 - ray.step_y) * 0.5) / dir_y;
		ray.distance = fabs(ray.distance);
		ray.wall_x = img->map.x + ray.distance * dir_x;
	}
	if (ray.distance < 0.000001)
		ray.distance = 0.00001;
	ray.wall_x -= floor(ray.wall_x);
	return (ray);
}

void	find_distance(t_data *img, t_raycasting ray, int count, float degree)
{
	int			x;
	float		hp;
	t_render	render;

	ray.distance *= cosf(degree);
	hp = DS * (HW / ray.distance);
	render.ceiling = (HE + hp * 0.5) * img->map.res_height;
	render.floor = (HE - hp * 0.5) * img->map.res_height;
	render.count = count;
	x = 0;
	while (x < render.floor)
	{
		pixel_to_image(img, x,
			img->map.res_length - count, img->map.ceiling_color);
		x ++;
	}
	print_texture(x, &render, img, ray);
	x = render.ceiling + 1;
	while (x <= img->map.res_height)
	{
		pixel_to_image(img, x,
			img->map.res_length - count, img->map.floor_color);
		x ++;
	}
}

static void	find_angle(t_data *img, float *angle)
{
	int		count;
	int		opposite;
	float	adjacent;

	opposite = img->map.res_length / 2;
	adjacent = (float)opposite / tanf((float)img->map.fov / 2 * RAD_CONV);
	count = 0;
	while (opposite >= 0)
	{
		angle[count] = -atanf(opposite / adjacent);
		angle[img->map.res_length - count] = -angle[count];
		opposite --;
		count ++;
	}
}

int	raycasting(t_data *img)
{
	double			tmp;
	int				count;
	t_raycasting	raycast;
	float			*angle;

	angle = malloc(sizeof(float) * (img->map.res_length + 1));
	if (!angle)
		return (1);
	find_angle(img, angle);
	count = 0;
	while (count < img->map.res_length)
	{
		tmp = (img->map.orientation.degree * RAD_CONV + angle[count]);
		raycast = intersection(img, cosf(tmp), sinf(tmp));
		find_distance(img, raycast, count, fabs(angle[count]));
		count ++;
	}
	free(angle);
	return (0);
}
