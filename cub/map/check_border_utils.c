/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:13:30 by teusebio          #+#    #+#             */
/*   Updated: 2022/04/07 19:13:32 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	check_last_str(int index, t_obj *o)
{
	int	i;

	i = 0;
	while (o->map[index][i])
	{
		if (o->map[index][i] != '1' && o->map[index][i] != ' ')
		{
			printf("Error: wrong map!\n");
			return (free_and_return(o));
		}
		i++;
	}
	return (0);
}

int	check_next_less_len(int index, t_obj *o)
{
	int	i;

	i = 0;
	while (i < o->next_len)
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
	i--;
	while (i < o->current_len)
	{
		if (o->map[index][i] != ' ' && o->map[index][i] != '1')
		{
			printf("Error: wrong map!\n");
			return (free_and_return(o));
		}
		i++;
	}
	return (0);
}

int	check_current_less_len(int index, t_obj *o)
{
	int	i;

	i = 0;
	while (i < o->current_len)
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
	i--;
	while (i < o->next_len)
	{
		if (o->map[index + 1][i] != ' ' && o->map[index + 1][i] != '1')
		{
			printf("Error: wrong map!\n");
			return (free_and_return(o));
		}
		i++;
	}
	return (0);
}
