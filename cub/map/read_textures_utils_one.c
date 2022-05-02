/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:41:26 by teusebio          #+#    #+#             */
/*   Updated: 2022/03/04 17:41:28 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	free_strings(t_obj *o)
{
	if (o->count_no == 1)
		free(o->no);
	if (o->count_so == 1)
		free(o->so);
	if (o->count_we == 1)
		free(o->we);
	if (o->count_ea == 1)
		free(o->ea);
	if (o->count_floor == 1)
		free(o->floor_rgb);
	if (o->count_ceil == 1)
		free(o->ceiling_rgb);
}

int	init_first_str_map(char *res, t_obj *o)
{
	if (!res)
	{
		printf("Error: map not found!\n");
		free_o(o);
		return (1);
	}
	o->first_str_of_map = res;
	return (0);
}

int	init_o_texture_two(t_obj *o)
{
	if (ft_strcmp(o->arr[0], "EA") == 0)
	{
		if (check_duplicate_and_init(&o->count_ea, &o->ea, o))
			return (1);
	}
	else if (ft_strcmp(o->arr[0], "F") == 0)
	{
		if (check_duplicate_and_init(&o->count_floor, &o->floor_rgb, o))
			return (1);
	}
	else if (ft_strcmp(o->arr[0], "C") == 0)
	{
		if (check_duplicate_and_init(&o->count_ceil, &o->ceiling_rgb, o))
			return (1);
	}
	else
	{
		if (check_arr_len(o->arr))
			return (print_error_bad_texture());
		printf("Error: bad path or color key\n");
		return (1);
	}
	return (0);
}

int	check_arr_len(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
		count++;
	if (count != 2)
		return (1);
	return (0);
}
