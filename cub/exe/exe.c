/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:46:13 by teusebio          #+#    #+#             */
/*   Updated: 2022/04/05 09:46:15 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_img(char *path, void **img, int **data, t_obj *o)
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	*img = mlx_xpm_file_to_image(o->mlx, path, &o->tex_w, &o->tex_h);
	if (!*img)
	{
		printf("Error: wrong path!\n");
		free_o(o);
		exit(EXIT_FAILURE);
	}
	*data = (int *)mlx_get_data_addr(
			*img, &bits_per_pixel, &size_line, &endian);
	if (!*data)
	{
		printf("Error: wrong path!\n");
		mlx_destroy_image(o->mlx, *img);
		free_o(o);
		exit(EXIT_FAILURE);
	}
}

void	init_xpm(int direction, t_obj *o)
{
	if (direction == WALL_NORTH)
		init_img(o->no, &o->img_no, &o->data_no, o);
	else if (direction == WALL_SOUTH)
		init_img(o->so, &o->img_so, &o->data_so, o);
	else if (direction == WALL_WEST)
		init_img(o->we, &o->img_we, &o->data_we, o);
	else if (direction == WALL_EAST)
		init_img(o->ea, &o->img_ea, &o->data_ea, o);
}

int	key_hook(int keycode, t_obj *o)
{
	if (keycode == 13 || keycode == 126)
		move_up(o);
	else if (keycode == 0 || keycode == 123)
		turn_left(o);
	else if (keycode == 2 || keycode == 124)
		turn_right(o);
	else if (keycode == 1 || keycode == 125)
		move_down(o);
	else if (keycode == 53)
	{
		free_arr(o->map);
		free_o(o);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_game(t_obj *o)
{
	mlx_destroy_image(o->mlx, o->img_no);
	mlx_destroy_image(o->mlx, o->img_so);
	mlx_destroy_image(o->mlx, o->img_we);
	mlx_destroy_image(o->mlx, o->img_ea);
	free_arr(o->map);
	free_o(o);
	exit(EXIT_SUCCESS);
}

void	exe_game(t_obj *o)
{
	init_color(&o->ceiling_rgb, &o->ceiling_color, o);
	init_color(&o->floor_rgb, &o->floor_color, o);
	o->mlx = mlx_init();
	o->win = mlx_new_window(o->mlx, WIDTH, HEIGHT, "cub3D");
	mlx_hook(o->win, 17, 1L << 0, close_game, o);
	mlx_hook(o->win, 02, 1L << 0, key_hook, o);
	init_xpm(WALL_NORTH, o);
	init_xpm(WALL_SOUTH, o);
	init_xpm(WALL_EAST, o);
	init_xpm(WALL_WEST, o);
	fill_window(o);
	mlx_loop(o->mlx);
	free_arr(o->map);
	free_o(o);
}
