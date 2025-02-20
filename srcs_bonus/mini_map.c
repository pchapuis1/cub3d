/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:54:27 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/22 17:37:31 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	print_pixels(t_data *img, int x, int y, int color)
{
	int	size;
	int	i;
	int	j;

	size = 25;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == 0 || j == 0 || i + 1 == size || j + 1 == size)
				pixel_to_image(img, y + j, x + i, 0x505050);
			else
				pixel_to_image(img, y + j, x + i, color);
			j ++;
		}
		i ++;
	}
	return (0);
}

static void	mini_map_init(t_pos_int *start, t_pos_int *max, \
	t_pos_int *incr, t_data *g)
{
	start->y = (int)(g->map.y) - 6;
	start->x = (int)(g->map.x) - 6;
	max->y = (int)(g->map.y) + 6;
	max->x = (int)(g->map.x) + 6;
	incr->y = -1;
	incr->x = -1;
}

static void	print_elem(t_data *g, t_pos_int start, t_pos_int incr, int posx)
{
	if (g->map.map[start.y + incr.y][start.x + incr.x] == '1')
		print_pixels(g, posx + incr.x * SIZE, incr.y * SIZE + SIZE, 0x666666);
	else if (g->map.map[start.y + incr.y][start.x + incr.x] == '0')
		print_pixels(g, posx + incr.x * SIZE, incr.y * SIZE + SIZE, 0xc5c5c5);
	else if (g->map.map[start.y + incr.y][start.x + incr.x] == 'D' \
		|| g->map.map[start.y + incr.y][start.x + incr.x] == 'd')
		print_pixels(g, posx + incr.x * SIZE, incr.y * SIZE + SIZE, 0x1E7FCB);
}

int	mini_map(t_data *g)
{
	t_pos_int	start;
	t_pos_int	max;
	t_pos_int	incr;
	int			posx;

	mini_map_init(&start, &max, &incr, g);
	posx = g->map.res_length - SIZE * 14;
	while (start.y + ++incr.y <= max.y)
	{
		incr.x = -1;
		while (start.x + ++incr.x <= max.x)
		{
			if (start.y + incr.y >= 0 && start.y + incr.y < g->map.height \
				&& start.x + incr.x >= 0 && start.x + incr.x <= g->map.width)
			{
				print_elem(g, start, incr, posx);
			}
		}
	}
	print_pixels(g, g->map.res_length - SIZE * 8, SIZE * 6 + SIZE, 0x00000000);
	return (0);
}
