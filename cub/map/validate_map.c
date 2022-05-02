/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:51:35 by teusebio          #+#    #+#             */
/*   Updated: 2022/04/01 10:51:38 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_direction(int y, int x, t_obj *o)
{
	if (o->map[y][x] == 'N')
	{
		o->dir_y = -1;
		o->dir_x = 0;
	}
	else if (o->map[y][x] == 'S')
	{
		o->dir_y = 1;
		o->dir_x = 0;
	}
	else if (o->map[y][x] == 'E')
	{
		o->dir_y = 0;
		o->dir_x = 1;
	}
	else if (o->map[y][x] == 'W')
	{
		o->dir_y = 0;
		o->dir_x = -1;
	}
}

int	free_and_return(t_obj *o)
{
	free_arr(o->map);
	free_o(o);
	return (1);
}

int	check_symbol(int y, int x, t_obj *o)
{
	if (o->map[y][x] == '0' || o->map[y][x] == '1' || o->map[y][x] == ' ')
		return (0);
	else if (o->map[y][x] == 'N' || o->map[y][x] == 'S'
	|| o->map[y][x] == 'E' || o->map[y][x] == 'W')
	{
		o->player_y = y + 0.5;
		o->player_x = x + 0.5;
		init_direction(y, x, o);
		init_camera_plane(o);
		o->player_count++;
		if (o->player_count > 1)
			return (1);
		return (0);
	}
	else
		return (1);
}

int	validate_chars(t_obj *o)
{
	int	y;
	int	x;

	y = 0;
	while (o->map[y])
	{
		x = 0;
		while (o->map[y][x])
		{
			if (check_symbol(y, x, o))
			{
				printf("Error: not allowed symbol or too mush players!\n");
				return (free_and_return(o));
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	validate_map(t_obj *o)
{
	if (validate_chars(o))
		return (1);
	if (check_player_count(o))
		return (1);
	if (check_border(o))
		return (1);
	return (0);
}
