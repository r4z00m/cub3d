/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 09:13:01 by teusebio          #+#    #+#             */
/*   Updated: 2022/03/05 09:13:08 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

void	free_arr(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

void	free_o(t_obj *o)
{
	free(o->no);
	free(o->we);
	free(o->so);
	free(o->ea);
	free(o->floor_rgb);
	free(o->ceiling_rgb);
}

void	init_o_two(t_obj *o)
{
	o->mlx = NULL;
	o->win = NULL;
	o->img = NULL;
	o->img_no = NULL;
	o->img_so = NULL;
	o->img_we = NULL;
	o->img_ea = NULL;
	o->data = NULL;
	o->data_no = NULL;
	o->data_so = NULL;
	o->data_we = NULL;
	o->data_ea = NULL;
}

void	init_o_one(t_obj *o)
{
	o->map = NULL;
	o->arr = NULL;
	o->first_str_of_map = NULL;
	o->no = NULL;
	o->so = NULL;
	o->we = NULL;
	o->ea = NULL;
	o->floor_rgb = NULL;
	o->ceiling_rgb = NULL;
	o->player_count = 0;
	o->count_no = 0;
	o->count_so = 0;
	o->count_we = 0;
	o->count_ea = 0;
	o->count_floor = 0;
	o->count_ceil = 0;
}

int	main(int argc, char **argv)
{
	t_obj	o;

	init_o_one(&o);
	init_o_two(&o);
	if (argc != 2)
	{
		printf("Wrong count arguments!\n");
		return (1);
	}
	if (read_file(argv[1], &o))
		return (1);
	exe_game(&o);
}
