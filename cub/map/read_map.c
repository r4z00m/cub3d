/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:42:24 by teusebio          #+#    #+#             */
/*   Updated: 2022/03/04 17:42:27 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	joiner(char **str, char **res)
{
	char	*tmp;

	tmp = *str;
	*str = ft_strjoin(*str, "\n");
	if (!*str)
	{
		free(tmp);
		free(*res);
		return (1);
	}
	free(tmp);
	tmp = *res;
	*res = ft_strjoin(*res, *str);
	if (!*res)
	{
		free(tmp);
		free(*str);
		return (1);
	}
	free(tmp);
	return (0);
}

void	pass_empty_strings(int fd, t_obj *o)
{
	char	*tmp;

	while (o->first_str_of_map)
	{
		if (ft_strlen(o->first_str_of_map) == 0)
		{
			tmp = o->first_str_of_map;
			o->first_str_of_map = get_next_line(fd);
			free(tmp);
		}
		else
			break ;
	}
}

int	check_gap(int fd, char **str, char *res, t_obj *o)
{
	char	*tmp;

	if (ft_strlen(*str) == 1)
	{
		while (*str)
		{
			if (ft_strlen(*str) > 1)
			{
				printf("Error: gap in map\n");
				free(res);
				free(*str);
				free_o(o);
				return (1);
			}
			tmp = *str;
			*str = get_next_line(fd);
			free(tmp);
		}
	}
	return (0);
}

int	read_map_helper(t_obj *o, int fd, char **str, char **res)
{
	if (ft_strlen(o->first_str_of_map) == 0)
		pass_empty_strings(fd, o);
	*str = o->first_str_of_map;
	if (!*str)
	{
		printf("Error: map not found!\n");
		free_o(o);
		return (1);
	}
	*res = ft_strjoin(*str, "\n");
	if (!*res)
	{
		free(str);
		free_o(o);
		return (1);
	}
	return (0);
}

int	read_map(int fd, t_obj *o)
{
	char	*res;
	char	*str;
	char	*tmp1;

	if (read_map_helper(o, fd, &str, &res))
		return (1);
	while (str)
	{
		if (check_gap(fd, &str, res, o))
			return (1);
		tmp1 = str;
		str = get_next_line(fd);
		if (str)
		{
			if (joiner(&str, &res))
				return (1);
		}
		free(tmp1);
	}
	if (init_map(res, o))
		return (1);
	if (validate_map(o))
		return (1);
	return (0);
}
