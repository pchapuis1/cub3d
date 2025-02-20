/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:09:43 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/23 13:39:11 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_render
{
	int		*dst;
	int		img_height;
	int		img_width;
	float	ceiling;
	float	floor;
	int		count;
}	t_render;

typedef struct s_raycasting
{
	float	distance;
	float	wall_x;
	float	dist_x;
	float	dist_y;
	int		side;
	int		step_x;
	int		step_y;
}	t_raycasting;

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_pos_int
{
	int	x;
	int	y;
}	t_pos_int;

typedef struct s_orientation
{
	float	x;
	float	y;
	float	degree;
}	t_orientation;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		end;
	int		img_width;
	int		img_height;
}	t_texture;

typedef struct s_input
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left_arrow;
	int	right_arrow;
}	t_input;

typedef struct s_map
{
	int				fov;
	int				res_length;
	int				res_height;

	char			**map;
	char			empty;
	char			wall;
	int				width;
	int				height;

	char			*path_wall_north;
	char			*path_wall_south;
	char			*path_wall_west;
	char			*path_wall_east;
	int				status_path_wall_north;
	int				status_path_wall_south;
	int				status_path_wall_west;
	int				status_path_wall_east;

	t_texture		north;
	t_texture		south;
	t_texture		west;
	t_texture		east;

	unsigned int	ceiling_color;
	unsigned int	floor_color;

	float			x;
	float			y;
	float			player_speed;
	t_orientation	orientation;
	int				verif_exit;
	int				verif_item;
	t_input			input;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		len;
	int		end;
	int		img_width;
	int		img_height;
	t_map	map;
}	t_data;

int				error_config(char c);
void			ft_free(char **map);
void			free_path(t_data *img);
void			end(int result);
int				close_win(t_data *img, int result, int nb, int before);
void			destroy_img(t_data *img, int n);

int				config_map(t_data *img, char **argv);
int				parsing_map(char **file, t_data *img, int start);
char			*get_next_line(int fd, char *tmp);
int				check_map(t_map data);
int				is_map_split(char *file);
int				check_name(char *file, char *str);
int				find_player_position(t_data *img);
int				is_position_valid(t_data *img);
int				is_direction(int c);
int				count_arg(char **map, char c);

t_map			fill_info_map(void);
int				fill_path(t_data *img);
void			map_dimension(t_data *img);
int				init_info(t_data *img);
int				init_img(t_data *img);

void			hook(t_data *img);
void			move_forward(t_data *img);
void			move_back(t_data *img);
void			move_left(t_data *img);
void			move_right(t_data *img);

void			cam_right(t_data *img);
void			cam_left(t_data *img);

int				split_info(char **file, t_data *img);
t_raycasting	find_first(float x, float y, t_data *img, t_pos delta);
void			find_delta(t_pos *delta, float dir_x, float dir_y);
void			find_contact(t_raycasting *ray, t_pos delta, t_data *img, \
	t_pos_int *pos);
void			pixel_to_image(t_data *img, int y, int x, int color);
int				raycasting(t_data *img);
void			print_texture(int x, t_render *render, t_data *img, \
	t_raycasting ray);

char			*last_word(char *str);
char			*first_word(char *str);
int				count_word(char *str);

int				get_color(char *id, char *line, t_data *img);
int				ft_strcmp(const char *s1, const char *s2);

/* PI / 180 */
# define RAD_CONV 0.01745329

/* distance of the screen */
# define DS 1.5

/* heigth of the wall */
# define HW 1

/* heigth of the eye */
# define HE 0.5
# define SIZE 25
# define NORTH 1
# define SOUTH 2
# define WEST 3
# define EAST 4

#endif
