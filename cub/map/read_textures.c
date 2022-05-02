/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:41:54 by teusebio          #+#    #+#             */
/*   Updated: 2022/04/07 18:41:56 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	init_o_texture_helper(char **str, t_obj *o)
{
	if (check_arr_len(o->arr))
		return (print_error_bad_texture());
	*str = ft_strdup(o->arr[1]);
	return (0);
}

int	check_duplicate_and_init(int *count, char **str, t_obj *o)
{
	(*count)++;
	if (*count > 1)
	{
		printf("Error: duplicate path or color\n");
		free(*str);
		return (1);
	}
	if (init_o_texture_helper(str, o))
		return (1);
	return (0);
}

int	init_o_texture(t_obj *o)
{
	if (ft_strcmp(o->arr[0], "NO") == 0)
	{
		if (check_duplicate_and_init(&o->count_no, &o->no, o))
			return (1);
	}
	else if (ft_strcmp(o->arr[0], "SO") == 0)
	{
		if (check_duplicate_and_init(&o->count_so, &o->so, o))
			return (1);
	}
	else if (ft_strcmp(o->arr[0], "WE") == 0)
	{
		if (check_duplicate_and_init(&o->count_we, &o->we, o))
			return (1);
	}
	else
		return (init_o_texture_two(o));
	return (0);
}

int	read_textures_helper(char *res, int *count, t_obj *o)
{
	o->arr = ft_split(res, ' ');
	if (!o->arr)
		return (print_error_split_malloc(res));
	if (init_o_texture(o))
	{
		free(res);
		free_strings(o);
		free_arr(o->arr);
		return (1);
	}
	(*count)++;
	free_arr(o->arr);
	return (0);
}

int	read_textures(int fd, t_obj *o)
{
	char	*res;
	char	*tmp;
	int		count;

	res = get_next_line(fd);
	if (!res)
		return (print_error_empty_file());
	count = 0;
	while (count < 6)
	{
		tmp = res;
		if (ft_strlen(res) != 0)
		{
			if (read_textures_helper(res, &count, o))
				return (1);
		}
		res = get_next_line(fd);
		if (count != 6 && !res)
			return (print_error_not_found(tmp, o));
		free(tmp);
	}
	if (init_first_str_map(res, o))
		return (1);
	return (0);
}
