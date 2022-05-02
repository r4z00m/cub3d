/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:45:46 by teusebio          #+#    #+#             */
/*   Updated: 2022/04/05 09:45:48 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	fill_vertical(int x, int side, t_obj *o)
{
	int	line_height;

	if (x == WIDTH / 2)
		o->dist = o->perp_wall_dist;
	line_height = HEIGHT / o->perp_wall_dist;
	o->draw_start = -line_height / 2 + HEIGHT / 2;
	if (o->draw_start < 0)
		o->draw_start = 0;
	o->draw_end = line_height / 2 + HEIGHT / 2;
	if (o->draw_end >= HEIGHT)
		o->draw_end = HEIGHT - 1;
	init_texture(side, o);
	fill_ceil(x, o->draw_start, o);
	fill_texture(x, side, line_height, o);
	fill_floor(x, o->draw_end, o);
}

int	throw_ray(t_obj *o)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (o->side_dist_x < o->side_dist_y)
		{
			o->side_dist_x += o->delta_dist_x;
			o->map_x += o->step_x;
			side = 0;
		}
		else
		{
			o->side_dist_y += o->delta_dist_y;
			o->map_y += o->step_y;
			side = 1;
		}
		if (o->map[o->map_y][o->map_x] == '1')
			hit = 1;
	}
	return (side);
}

void	init_sides(t_obj *o)
{
	if (o->ray_dir_x < 0)
	{
		o->step_x = -1;
		o->side_dist_x = (o->player_x - o->map_x) * o->delta_dist_x;
	}
	else
	{
		o->step_x = 1;
		o->side_dist_x = (o->map_x + 1.0 - o->player_x) * o->delta_dist_x;
	}
	if (o->ray_dir_y < 0)
	{
		o->step_y = -1;
		o->side_dist_y = (o->player_y - o->map_y) * o->delta_dist_y;
	}
	else
	{
		o->step_y = 1;
		o->side_dist_y = (o->map_y + 1.0 - o->player_y) * o->delta_dist_y;
	}
}

void	init_deltas(int x, t_obj *o)
{
	o->camera_x = 2 * x / (double) WIDTH - 1;
	o->ray_dir_x = o->dir_x + o->plane_x * o->camera_x;
	o->ray_dir_y = o->dir_y + o->plane_y * o->camera_x;
	o->map_x = o->player_x;
	o->map_y = o->player_y;
	if (o->ray_dir_x == 0)
		o->delta_dist_x = MY_INT_MAX;
	else
		o->delta_dist_x = fabs(1 / o->ray_dir_x);
	if (o->ray_dir_y == 0)
		o->delta_dist_y = MY_INT_MAX;
	else
		o->delta_dist_y = fabs(1 / o->ray_dir_y);
}

void	fill_window(t_obj *o)
{
	int		x;
	int		side;
	t_data	img;

	img.img = mlx_new_image(o->mlx, WIDTH, HEIGHT);
	img.data = mlx_get_data_addr(
			img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	o->img = &img;
	x = 0;
	while (x < WIDTH)
	{
		init_deltas(x, o);
		init_sides(o);
		side = throw_ray(o);
		if (side == 0)
			o->perp_wall_dist = o->side_dist_x - o->delta_dist_x;
		else
			o->perp_wall_dist = o->side_dist_y - o->delta_dist_y;
		fill_vertical(x, side, o);
		x++;
	}
	mlx_put_image_to_window(o->mlx, o->win, o->img->img, 0, 0);
	mlx_destroy_image(o->mlx, o->img->img);
}
