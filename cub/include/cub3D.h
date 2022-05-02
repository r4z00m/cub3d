/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 09:12:25 by teusebio          #+#    #+#             */
/*   Updated: 2022/03/05 09:12:28 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# define BUFFER_SIZE 1024
# define ROT_SPEED 0.1
# define WIDTH 1920
//# define WIDTH 1280
# define HEIGHT 1080
//# define HEIGHT 720
# define MY_INT_MAX 2147483647
# define WALL_NORTH 0
# define WALL_SOUTH 1
# define WALL_WEST 2
# define WALL_EAST 3

typedef struct s_data
{
	void	*img;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_obj
{
	char	**map;
	char	**arr;
	char	*first_str_of_map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*floor_rgb;
	char	*ceiling_rgb;
	int		player_count;
	double	player_y;
	double	player_x;
	double	dir_y;
	double	dir_x;
	double	plane_y;
	double	plane_x;
	int		count_no;
	int		count_so;
	int		count_we;
	int		count_ea;
	int		count_floor;
	int		count_ceil;
	int		current_len;
	int		next_len;
	void	*mlx;
	void	*win;
	t_data	*img;
	void	*img_no;
	void	*img_so;
	void	*img_we;
	void	*img_ea;
	int		*data;
	int		*data_no;
	int		*data_so;
	int		*data_we;
	int		*data_ea;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		ceiling_color;
	int		floor_color;
	int		draw_start;
	int		draw_end;
	int		wall_side;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	int		tex_w;
	int		tex_h;
	double	dist;
}			t_obj;

////////// read_file.c //////////
int		ft_strcmp(char *s1, char *s2);
int		check_extension(char *filename);
int		read_file(char *filename, t_obj *o);

////////// get_next_line.c //////////
char	*get_next_line(int fd);

////////// read_textures.c //////////
int		read_textures(int fd, t_obj *o);
int		read_textures_helper(char *res, int *count, t_obj *o);
int		init_o_texture(t_obj *o);
int		check_duplicate_and_init(int *count, char **str, t_obj *o);
int		init_o_texture_helper(char **str, t_obj *o);

////////// read_textures_utils_one.c //////////
int		check_arr_len(char **arr);
int		init_o_texture_two(t_obj *o);
int		init_first_str_map(char *res, t_obj *o);
void	free_strings(t_obj *o);

////////// read_map.c //////////
int		read_map(int fd, t_obj *o);
int		read_map_helper(t_obj *o, int fd, char **str, char **res);
int		check_gap(int fd, char **str, char *res, t_obj *o);
void	pass_empty_strings(int fd, t_obj *o);
int		joiner(char **str, char **res);

////////// print_read_err.c //////////
int		print_error_bad_texture(void);
int		print_error_empty_file(void);
int		print_error_split_malloc(char *res);
int		print_error_not_found(char *tmp, t_obj *o);

////////// validate_map.c //////////
int		validate_map(t_obj *o);
int		validate_chars(t_obj *o);
int		check_symbol(int y, int x, t_obj *o);
void	init_direction(int y, int x, t_obj *o);
int		free_and_return(t_obj *o);

////////// validate_utils_one.c //////////
void	init_camera_plane(t_obj *o);
int		check_player_count(t_obj *o);
int		init_map(char *res, t_obj *o);

////////// check_border.c //////////
int		check_border(t_obj *o);
int		check_first_str(t_obj *o);
int		check_mid_str(int index, t_obj *o);
int		check_equals_len(int index, t_obj *o);
int		check_around(int index, int i, t_obj *o);

////////// check_border_utils.c //////////
int		check_current_less_len(int index, t_obj *o);
int		check_next_less_len(int index, t_obj *o);
int		check_last_str(int index, t_obj *o);

////////// exe.c //////////
void	exe_game(t_obj *o);
int		close_game(t_obj *o);
int		key_hook(int keycode, t_obj *o);
void	init_xpm(int direction, t_obj *o);
void	init_img(char *path, void **img, int **addr, t_obj *o);

////////// exe_utils_one.c //////////
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	count_len(long tmp, int base, int *len);
char	*ft_itoa_base(long nbr, int base);

////////// init_color.c //////////
void	init_color(char **color, int *result, t_obj *o);
char	**init_arr(char **color, t_obj *o);
int		arr_len(char **arr);
void	print_err_rgb(char **arr, t_obj *o);
int		*init_ints(char **arr, t_obj *o);

////////// init_color_two.c //////////
void	print_fatal_malloc(char **arr, t_obj *o);
int		check_is_digit(char *str);
void	print_err_exit(char **arr, int **ints, t_obj *o);
void	while_helper(char **color, int *ints, int i);
int		ft_atoh(char *str);

////////// fill_window.c //////////
void	fill_window(t_obj *o);
void	init_deltas(int x, t_obj *o);
void	init_sides(t_obj *o);
int		throw_ray(t_obj *o);
void	fill_vertical(int x, int side, t_obj *o);

////////// fill_window_two.c //////////
void	init_texture(int side, t_obj *o);
void	fill_ceil(int x, int draw_start, t_obj *o);
void	fill_texture(int x, int side, int line_height, t_obj *o);
void	init_wall_x(int side, t_obj *o);
void	fill_floor(int x, int draw_end, t_obj *o);

////////// move.c //////////
void	turn_left(t_obj *o);
void	turn_right(t_obj *o);
int		check_collision(t_obj *o);
void	move_up(t_obj *o);
void	move_down(t_obj *o);

////////// main.c //////////
void	free_arr(char **arr);
void	free_o(t_obj *o);
void	init_o_two(t_obj *o);
void	init_o_one(t_obj *o);
int		main(int argc, char **argv);

#endif
