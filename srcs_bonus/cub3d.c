/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:28:29 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/23 15:26:53 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	close_win(t_data *img, int result, int nb, int before)
{
	if (result < 0)
		result = 2;
	end(result);
	if (img->map.map)
		ft_free(img->map.map);
	destroy_img(img, nb);
	if (before != 1)
	{
		mlx_destroy_image(img->mlx, img->img_ptr);
		mlx_destroy_window(img->mlx, img->mlx_win);
	}
	free_path(img);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	if (before != 1)
		exit(0);
	return (0);
}

int	rendering(t_data *img)
{
	if (img->map.input.w == 1)
		move_forward(img);
	if (img->map.input.a == 1)
		move_left(img);
	if (img->map.input.s == 1)
		move_back(img);
	if (img->map.input.d == 1)
		move_right(img);
	if (img->map.input.left_arrow == 1)
		cam_left(img);
	if (img->map.input.right_arrow == 1)
		cam_right(img);
	if (raycasting(img) == 1)
		close_win(img, 3, 6, 0);
	mini_map(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	img;
	int		tmp;

	if (argc != 2)
		return (error_config('L'));
	if (config_map(&img, argv) == 1)
		return (free_path(&img), 1);
	if (init_info(&img) == 1)
		return (free_path(&img), 1);
	tmp = fill_path(&img);
	if (tmp != 0)
		return (close_win(&img, 5, tmp, 1), 1);
	if (init_img(&img) == 1)
		return (close_win(&img, 4, 6, 1), 1);
	hook(&img);
	mlx_loop_hook(img.mlx, rendering, &img);
	mlx_loop(img.mlx);
	return (0);
}
