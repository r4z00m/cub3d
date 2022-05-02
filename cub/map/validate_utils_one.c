/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:52:48 by teusebio          #+#    #+#             */
/*   Updated: 2022/03/05 15:52:50 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	init_map(char *res, t_obj *o)
{
	o->map = ft_split(res, '\n');
	if (!o->map)
	{
		free(res);
		free_o(o);
		return (1);
	}
	free(res);
	return (0);
}

int	check_player_count(t_obj *o)
{
	int	count;

	count = 0;
	while (o->map[count])
		count++;
	if (count < 3)
	{
		printf("Error: wrong map!\n");
		return (free_and_return(o));
	}
	if (o->player_count == 0)
	{
		printf("Error: one player needed!\n");
		return (free_and_return(o));
	}
	return (0);
}

void	init_camera_plane(t_obj *o)
{
	if (o->dir_x == 0 && o->dir_y == -1)
	{
		o->plane_x = 0.66;
		o->plane_y = 0;
	}
	else if (o->dir_x == 0 && o->dir_y == 1)
	{
		o->plane_x = -0.66;
		o->plane_y = 0;
	}
	else if (o->dir_y == 0 && o->dir_x == -1)
	{
		o->plane_x = 0;
		o->plane_y = -0.66;
	}
	else if (o->dir_y == 0 && o->dir_x == 1)
	{
		o->plane_x = 0;
		o->plane_y = 0.66;
	}
}
