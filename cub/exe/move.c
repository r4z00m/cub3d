/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:09:36 by teusebio          #+#    #+#             */
/*   Updated: 2022/04/07 18:09:37 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	turn_left(t_obj *o)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = o->dir_x;
	o->dir_x = o->dir_x * cos(-ROT_SPEED) - o->dir_y * sin(-ROT_SPEED);
	o->dir_y = old_dir_x * sin(-ROT_SPEED) + o->dir_y * cos(-ROT_SPEED);
	old_plane_x = o->plane_x;
	o->plane_x = o->plane_x * cos(-ROT_SPEED) - o->plane_y * sin(-ROT_SPEED);
	o->plane_y = old_plane_x * sin(-ROT_SPEED) + o->plane_y * cos(-ROT_SPEED);
	fill_window(o);
}

void	turn_right(t_obj *o)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = o->dir_x;
	o->dir_x = o->dir_x * cos(ROT_SPEED) - o->dir_y * sin(ROT_SPEED);
	o->dir_y = old_dir_x * sin(ROT_SPEED) + o->dir_y * cos(ROT_SPEED);
	old_plane_x = o->plane_x;
	o->plane_x = o->plane_x * cos(ROT_SPEED) - o->plane_y * sin(ROT_SPEED);
	o->plane_y = old_plane_x * sin(ROT_SPEED) + o->plane_y * cos(ROT_SPEED);
	fill_window(o);
}

void	move_up(t_obj *o)
{
	if (o->dist > 0.66)
	{
		o->player_y += o->dir_y / 4;
		o->player_x += o->dir_x / 4;
		fill_window(o);
	}
}

void	move_down(t_obj *o)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = o->player_x - 0.66 * o->dir_x;
	new_pos_y = o->player_y - 0.66 * o->dir_y;
	if (o->map[new_pos_y][new_pos_x] != '1')
	{
		o->player_y -= o->dir_y / 4;
		o->player_x -= o->dir_x / 4;
		fill_window(o);
	}
}
