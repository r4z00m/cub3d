/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:40:56 by teusebio          #+#    #+#             */
/*   Updated: 2022/03/04 17:41:02 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i] && s2[i] && s1[i] == s2[i])
			i++;
		return (s1[i] - s2[i]);
	}
	return (1);
}

int	check_extension(char *filename)
{
	char	*point;

	if (filename[0] == '.')
	{
		printf("Error: wrong filename!\n");
		return (1);
	}
	point = ft_strchr(filename, '.');
	if (!point)
	{
		printf("Error: wrong extension!\n");
		return (1);
	}
	if (ft_strcmp(point, ".cub") != 0)
	{
		printf("Error: wrong extension!\n");
		return (1);
	}
	return (0);
}

int	read_file(char *filename, t_obj *o)
{
	int	fd;

	if (check_extension(filename))
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("cube3D");
		return (1);
	}
	if (read_textures(fd, o))
	{
		close(fd);
		return (1);
	}
	if (read_map(fd, o))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
