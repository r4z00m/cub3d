/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:07:01 by teusebio          #+#    #+#             */
/*   Updated: 2022/04/07 19:07:02 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	check_around(int index, int i, t_obj *o)
{
	if (i == 0)
	{
		printf("Error: wrong map!\n");
		return (free_and_return(o));
	}
	if (o->map[index - 1][i - 1] == ' ' || o->map[index - 1][i] == ' '
	|| o->map[index - 1][i + 1] == ' ' || o->map[index][i - 1] == ' '
	|| o->map[index][i + 1] == ' ' || o->map[index + 1][i - 1] == ' '
	|| o->map[index + 1][i] == ' ' || o->map[index + 1][i + 1] == ' '
	|| o->map[index][i + 1] == 0)
	{
		printf("Error: wrong map!\n");
		return (free_and_return(o));
	}
	return (0);
}

int	check_equals_len(int index, t_obj *o)
{
	int	i;

	i = 0;
	while (o->map[index][i])
	{
		if (o->map[index][i] == '0' || o->map[index][i] == 'N'
		|| o->map[index][i] == 'S' || o->map[index][i] == 'W'
		|| o->map[index][i] == 'E')
		{
			if (check_around(index, i, o))
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_mid_str(int index, t_obj *o)
{
	o->current_len = ft_strlen(o->map[index]);
	o->next_len = ft_strlen(o->map[index + 1]);
	if (o->current_len == o->next_len)
	{
		if (check_equals_len(index, o))
			return (1);
	}
	else if (o->current_len < o->next_len)
	{
		if (check_current_less_len(index, o))
			return (1);
	}
	else
	{
		if (check_next_less_len(index, o))
			return (1);
	}
	return (0);
}

int	check_first_str(t_obj *o)
{
	int	i;

	i = 0;
	while (o->map[0][i])
	{
		if (o->map[0][i] != '1' && o->map[0][i] != ' ')
		{
			printf("Error: wrong map!\n");
			return (free_and_return(o));
		}
		i++;
	}
	return (0);
}

int	check_border(t_obj *o)
{
	int	i;

	i = 0;
	if (check_first_str(o))
		return (1);
	while (o->map[i + 1])
	{
		if (check_mid_str(i, o))
			return (1);
		i++;
	}
	if (check_last_str(i, o))
		return (1);
	return (0);
}
