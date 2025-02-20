/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:19:07 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/23 15:26:28 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_map	fill_info_map(void)
{
	t_map	data;

	data.empty = '0';
	data.wall = '1';
	return (data);
}

void	map_dimension(t_data *img)
{
	int	i;
	int	max;

	max = (int)ft_strlen(img->map.map[0]);
	i = 0;
	while (img->map.map[i])
	{
		if ((int)ft_strlen(img->map.map[i]) > max)
			max = (int)ft_strlen(img->map.map[i]);
		i ++;
	}
	img->map.width = max;
	img->map.height = i;
}

void	pixel_to_image(t_data *img, int y, int x, int color)
{
	int	*dst;

	if (x >= 0 && x < img->map.res_length && y > 0 && y < img->map.res_height)
	{
		dst = (int *)img->addr;
		dst[y * img->map.res_length + x] = color;
	}
}

int	init_info(t_data *img)
{
	img->map.res_length = 1920;
	img->map.res_height = 1080;
	img->map.fov = 66;
	img->map.player_speed = 0.043;
	img->map.input.w = 0;
	img->map.input.a = 0;
	img->map.input.s = 0;
	img->map.input.d = 0;
	img->map.input.left_arrow = 0;
	img->map.input.right_arrow = 0;
	img->mlx = mlx_init();
	if (!img->mlx)
		return (ft_free(img->map.map), 1);
	return (0);
}

int	init_img(t_data *img)
{
	t_data	*i;

	i = img;
	i->mlx_win = mlx_new_window(i->mlx, i->map.res_length,
			i->map.res_height, "cub3d");
	if (!i->mlx_win)
		return (1);
	i->img_ptr = mlx_new_image(i->mlx, i->map.res_length, i->map.res_height);
	if (!i->img_ptr)
		return (mlx_destroy_window(img->mlx, img->mlx_win), 1);
	i->addr = mlx_get_data_addr(i->img_ptr, &i->bpp, &i->len, &i->end);
	i->bpp /= 8;
	return (0);
}
