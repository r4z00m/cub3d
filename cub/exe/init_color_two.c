/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:12:48 by teusebio          #+#    #+#             */
/*   Updated: 2022/04/06 09:12:50 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_atoh(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 16 + str[i] - '0';
		else
			res = res * 16 + str[i] - 'A' + 10;
		i++;
	}
	return (res);
}

void	while_helper(char **color, int *ints, int i)
{
	char	*tmp;
	char	*res;

	tmp = *color;
	res = ft_itoa_base(ints[i], 16);
	*color = ft_strjoin(*color, res);
	free(res);
	free(tmp);
}

void	print_err_exit(char **arr, int **ints, t_obj *o)
{
	printf("Error: wrong RGB!\n");
	free_arr(arr);
	free(*ints);
	free_o(o);
	exit(EXIT_FAILURE);
}

int	check_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	print_fatal_malloc(char **arr, t_obj *o)
{
	printf("Error: fatal malloc!\n");
	free_arr(arr);
	free_o(o);
	exit(EXIT_FAILURE);
}
