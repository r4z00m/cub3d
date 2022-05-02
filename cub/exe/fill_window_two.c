/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:06:59 by teusebio          #+#    #+#             */
/*   Updated: 2022/04/07 18:07:01 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	fill_floor(int x, int draw_end, t_obj *o)
{
	int	i;

	i = draw_end;
	while (i < HEIGHT)
	{
		my_mlx_pixel_put(o->img, x, i, o->floor_color);
		i++;
	}
}

void	init_wall_x(int side, t_obj *o)
{
	if (side)
		o->wall_x = o->player_x + o->perp_wall_dist * o->ray_dir_x - o->map_x;
	else
		o->wall_x = o->player_y + o->perp_wall_dist * o->ray_dir_y - o->map_y;
}

void	fill_texture(int x, int side, int line_height, t_obj *o)
{
	int		y;
	int		color;
	double	step;
	double	tex_pos;

	init_wall_x(side, o);
	o->tex_x = o->wall_x * (double) o->tex_w;
	step = 1.0 * o->tex_h / line_height;
	tex_pos = (o->draw_start - HEIGHT / 2 + line_height / 2) * step;
	y = o->draw_start;
	while (y < o->draw_end)
	{
		o->tex_y = (int)tex_pos & (o->tex_h - 1);
		tex_pos += step;
		if (o->wall_side == WALL_NORTH)
			color = o->data_no[o->tex_h * o->tex_y + o->tex_x];
		else if (o->wall_side == WALL_SOUTH)
			color = o->data_so[o->tex_h * o->tex_y + o->tex_x];
		else if (o->wall_side == WALL_WEST)
			color = o->data_we[o->tex_h * o->tex_y + o->tex_x];
		else if (o->wall_side == WALL_EAST)
			color = o->data_ea[o->tex_h * o->tex_y + o->tex_x];
		my_mlx_pixel_put(o->img, x, y, color);
		y++;
	}
}

void	fill_ceil(int x, int draw_start, t_obj *o)
{
	int		i;

	i = 0;
	while (i < draw_start)
	{
		my_mlx_pixel_put(o->img, x, i, o->ceiling_color);
		i++;
	}
}

void	init_texture(int side, t_obj *o)
{
	if (side)
	{
		if (o->ray_dir_y < 0)
			o->wall_side = WALL_SOUTH;
		else
			o->wall_side = WALL_NORTH;
	}
	else
	{
		if (o->ray_dir_x < 0)
			o->wall_side = WALL_EAST;
		else
			o->wall_side = WALL_WEST;
	}
}
