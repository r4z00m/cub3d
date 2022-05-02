/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 08:35:34 by teusebio          #+#    #+#             */
/*   Updated: 2022/04/06 08:35:36 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	*init_ints(char **arr, t_obj *o)
{
	int	*ints;

	ints = malloc(sizeof(int *) * 3);
	if (!ints)
		print_fatal_malloc(arr, o);
	return (ints);
}

void	print_err_rgb(char **arr, t_obj *o)
{
	printf("Error: wrong RGB!\n");
	free_arr(arr);
	free_o(o);
	exit(EXIT_FAILURE);
}

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**init_arr(char **color, t_obj *o)
{
	char	**arr;

	arr = ft_split(*color, ',');
	if (!arr)
		exit(EXIT_FAILURE);
	if (arr_len(arr) != 3)
		print_err_rgb(arr, o);
	return (arr);
}

void	init_color(char **color, int *result, t_obj *o)
{
	int		i;
	char	**arr;
	int		*ints;

	arr = init_arr(color, o);
	ints = init_ints(arr, o);
	free(*color);
	*color = ft_strdup("");
	i = 0;
	while (arr[i])
	{
		if (check_is_digit(arr[i]))
			print_err_exit(arr, &ints, o);
		ints[i] = ft_atoi(arr[i]);
		if (ints[i] < 0 || ints[i] > 255)
			print_err_exit(arr, &ints, o);
		while_helper(color, ints, i);
		i++;
	}
	*result = ft_atoh(*color);
	free_arr(arr);
	free(ints);
}
