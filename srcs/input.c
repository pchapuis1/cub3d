/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:10:02 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/22 17:32:17 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_pressed(int key, t_data *img)
{
	if (key == 119)
		img->map.input.w = 1;
	else if (key == 115)
		img->map.input.s = 1;
	else if (key == 97)
		img->map.input.a = 1;
	else if (key == 100)
		img->map.input.d = 1;
	else if (key == 65363)
		img->map.input.right_arrow = 1;
	else if (key == 65361)
		img->map.input.left_arrow = 1;
	else if (key == 65307)
		close_win(img, 2, 5, 0);
	return (0);
}

static int	key_release(int key, t_data *img)
{
	if (key == 119)
		img->map.input.w = 0;
	else if (key == 115)
		img->map.input.s = 0;
	else if (key == 97)
		img->map.input.a = 0;
	else if (key == 100)
		img->map.input.d = 0;
	else if (key == 65363)
		img->map.input.right_arrow = 0;
	else if (key == 65361)
		img->map.input.left_arrow = 0;
	return (0);
}

void	hook(t_data *img)
{
	mlx_hook(img->mlx_win, 2, 1L << 0, key_pressed, img);
	mlx_hook(img->mlx_win, 3, 1L << 1, key_release, img);
	mlx_hook(img->mlx_win, 33, 1L << 0, close_win, img);
}
