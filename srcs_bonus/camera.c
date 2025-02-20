/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:51:10 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/22 17:31:37 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	cam_left(t_data *img)
{
	if (img->map.orientation.degree >= 360)
		img->map.orientation.degree = img->map.orientation.degree - 360;
	img->map.orientation.degree += 0.9;
	img->map.orientation.x = cosf(img->map.orientation.degree * RAD_CONV);
	img->map.orientation.y = sinf(img->map.orientation.degree * RAD_CONV);
}

void	cam_right(t_data *img)
{
	if (img->map.orientation.degree <= 0)
		img->map.orientation.degree = 360 - img->map.orientation.degree;
	img->map.orientation.degree -= 0.9;
	img->map.orientation.x = cosf(img->map.orientation.degree * RAD_CONV);
	img->map.orientation.y = sinf(img->map.orientation.degree * RAD_CONV);
}
