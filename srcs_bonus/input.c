/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:10:02 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/22 17:19:18 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
		close_win(img, 2, 6, 0);
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

static int	mouse_motion(int x, int y, void *param)
{
	t_data	*img;
	int		limit;

	(void)y;
	img = param;
	limit = img->map.res_length * 0.6;
	if (x < img->map.res_length - limit)
		img->map.input.left_arrow = 1;
	else if (x > limit)
		img->map.input.right_arrow = 1;
	else
	{
		img->map.input.left_arrow = 0;
		img->map.input.right_arrow = 0;
	}
	return (0);
}

static int	mouse_button(int button, int x, int y, void *param)
{
	t_data	*img;

	(void)x;
	(void)y;
	img = param;
	if (button == 1 && img->map.map[(int)(img->map.y - img->map.orientation.y)]
		[(int)(img->map.x + img->map.orientation.x)] == 'D')
	{
		img->map.map[(int)(img->map.y - img->map.orientation.y)] \
			[(int)(img->map.x + img->map.orientation.x)] = 'd';
	}
	else if (button == 1
		&& img->map.map[(int)(img->map.y - img->map.orientation.y)]
		[(int)(img->map.x + img->map.orientation.x)] == 'd')
	{
		if (img->map.map[(int)(img->map.y)][(int)(img->map.x)] != 'd')
			img->map.map[(int)(img->map.y - img->map.orientation.y)] \
				[(int)(img->map.x + img->map.orientation.x)] = 'D';
		if (position_valid(img) == 1)
		{
			img->map.x = floor(img->map.x) + 0.5;
			img->map.y = floor(img->map.y) + 0.5;
		}
	}
	return (0);
}

void	hook(t_data *img)
{
	mlx_hook(img->mlx_win, 2, 1L << 0, key_pressed, img);
	mlx_hook(img->mlx_win, 3, 1L << 1, key_release, img);
	mlx_hook(img->mlx_win, 33, 1L << 0, close_win, img);
	mlx_hook(img->mlx_win, 6, 1L << 6, mouse_motion, img);
	mlx_mouse_hook(img->mlx_win, mouse_button, img);
}
