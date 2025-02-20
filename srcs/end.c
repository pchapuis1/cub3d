/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:03:24 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/23 15:44:41 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_config(char c)
{
	if (c == 'C')
		ft_putstr_fd("Error\n1 start position\n", 2);
	else if (c == 'L')
		ft_putstr_fd("Error\nUsage: ./cub3d [*.cub]\n", 2);
	else if (c == 'I')
		ft_putstr_fd("Error\nThe file don't contain enough informations\n", 2);
	else if (c == 'W')
		ft_putstr_fd("Error\nThe map must be framed by wall\n", 2);
	else if (c == 'A')
		ft_putstr_fd("Error\nThere is an unknown character in the map\n", 2);
	else if (c == 'E')
		ft_putstr_fd("Error\nThe color isn't in RGB\n", 2);
	else if (c == 'F')
		ft_putstr_fd("Error\nThe informations aren't in the good format\n", 2);
	else if (c == 'T')
		ft_putstr_fd("Error\nThe textures aren't valid\n", 2);
	else if (c == 'X')
		ft_putstr_fd("Error\nThe textures aren't in format \".xpm\"\n", 2);
	else if (c == 'P')
		ft_putstr_fd("Error\nThe player can't be on edge of the map\n", 2);
	else if (c == 'D')
		ft_putstr_fd("Error\nThe informations are doubled\n", 2);
	else if (c == 'V')
		ft_putstr_fd("Error\nThe map is empty\n", 2);
	return (1);
}

void	end(int result)
{
	if (result == 0)
		ft_putstr_fd("You won!\n", 1);
	else if (result == 1)
		ft_putstr_fd("You lost!\n", 1);
	else if (result == 2)
		ft_putstr_fd("You left the game!\n", 1);
	else if (result == 3)
		ft_putstr_fd("Error malloc\n", 2);
	else if (result == 4)
		ft_putstr_fd("Error new window\n", 2);
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i ++;
	}
	free(map);
}

void	free_path(t_data *img)
{
	if (img->map.status_path_wall_north == 1)
		free(img->map.path_wall_north);
	if (img->map.status_path_wall_south == 1)
		free(img->map.path_wall_south);
	if (img->map.status_path_wall_east == 1)
		free(img->map.path_wall_east);
	if (img->map.status_path_wall_west == 1)
		free(img->map.path_wall_west);
}

void	destroy_img(t_data *img, int n)
{
	if (n > 1)
		mlx_destroy_image(img->mlx, img->map.north.img);
	if (n > 2)
		mlx_destroy_image(img->mlx, img->map.south.img);
	if (n > 3)
		mlx_destroy_image(img->mlx, img->map.west.img);
	if (n > 4)
		mlx_destroy_image(img->mlx, img->map.east.img);
}
