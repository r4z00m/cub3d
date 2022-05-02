/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:41:13 by teusebio          #+#    #+#             */
/*   Updated: 2022/03/04 17:41:15 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	print_error_bad_texture(void)
{
	printf("Error: bad texture or color path\n");
	return (1);
}

int	print_error_empty_file(void)
{
	printf("Error: empty file\n");
	return (1);
}

int	print_error_split_malloc(char *res)
{
	printf("Error: split malloc\n");
	free(res);
	return (1);
}

int	print_error_not_found(char *tmp, t_obj *o)
{
	printf("Error: not found some texture or color\n");
	free_strings(o);
	free(tmp);
	return (1);
}
