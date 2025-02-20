/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:32:23 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/23 15:37:19 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_name(char *file, char *str)
{
	int	i;

	i = 0;
	while (file[i])
		i ++;
	i --;
	if (file[i] != str[3] || file[i - 1] != str[2] || file[i - 2] != str[1]
		|| file[i - 3] != str[0])
		return (0);
	return (1);
}

static int	get_file(int fd, char **tmp, char **tmp1)
{
	char	*tmp2;

	tmp2 = ft_strdup(*tmp);
	if (!tmp2)
		return (free(*tmp), free(*tmp1), 1);
	if (*tmp)
		free(*tmp);
	*tmp = ft_strjoin(tmp2, *tmp1);
	if (!*tmp)
		return (free(tmp2), free(*tmp1), 1);
	free(tmp2);
	free(*tmp1);
	*tmp1 = get_next_line(fd, *tmp);
	return (0);
}

static char	**paste_file(int fd, t_data *img)
{
	char	**file;
	char	*tmp;
	char	*tmp1;

	tmp = ft_strdup("");
	if (!tmp)
		return (NULL);
	tmp1 = get_next_line(fd, tmp);
	while (tmp1 != NULL)
		if (get_file(fd, &tmp, &tmp1) == 1)
			return (NULL);
	free(tmp1);
	if (tmp[0] == '\0')
		return (ft_putstr_fd("Error\nEmpty file\n", 2), free(tmp), NULL);
	file = ft_split(tmp, '\n');
	if (file == NULL)
		return (free(tmp), NULL);
	if (split_info(file, img) != 0)
		return (free(tmp), NULL);
	if (is_map_split(tmp) == 1)
		return (free(tmp), ft_free(file), ft_free(img->map.map), \
			ft_putstr_fd("Error\nMap split\n", 2), NULL);
	return (free(tmp), file);
}

static int	parsing(char **argv, t_data *img)
{
	char	**file;
	int		fd;

	if (check_name(argv[1], ".cub") == 0)
		return (error_config('L'), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror(argv[1]), 1);
	file = paste_file(fd, img);
	if (file == NULL)
		return (1);
	ft_free(file);
	if (close(fd) == -1)
		return (ft_free(file), 1);
	return (0);
}

int	config_map(t_data *img, char **argv)
{
	img->map = fill_info_map();
	img->map.status_path_wall_east = 0;
	img->map.status_path_wall_west = 0;
	img->map.status_path_wall_north = 0;
	img->map.status_path_wall_south = 0;
	img->map.status_path_door = 0;
	if (parsing(argv, img) != 0)
		return (1);
	map_dimension(img);
	if (check_map(img->map) == 1)
		return (ft_free(img->map.map), 1);
	return (find_player_position(img));
}
