/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:39:08 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/19 12:38:09 by fbelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_text_path(t_data *img, char *dir, t_texture *texture)
{
	texture->img = mlx_xpm_file_to_image(img->mlx, dir, &texture->img_width,
			&texture->img_height);
	if (!texture->img)
		return (1);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->len, &texture->end);
	return (0);
}

int	fill_path(t_data *img)
{
	if (check_name(img->map.path_wall_north, ".xpm") == 0)
		return (error_config('X'), 1);
	if (check_text_path(img, img->map.path_wall_north, &img->map.north))
		return (error_config('T'), 1);
	if (check_name(img->map.path_wall_south, ".xpm") == 0)
		return (error_config('X'), 2);
	if (check_text_path(img, img->map.path_wall_south, &img->map.south))
		return (error_config('T'), 2);
	if (check_name(img->map.path_wall_west, ".xpm") == 0)
		return (error_config('X'), 3);
	if (check_text_path(img, img->map.path_wall_west, &img->map.west))
		return (error_config('T'), 3);
	if (check_name(img->map.path_wall_east, ".xpm") == 0)
		return (error_config('X'), 4);
	if (check_text_path(img, img->map.path_wall_east, &img->map.east))
		return (error_config('T'), 4);
	return (0);
}
