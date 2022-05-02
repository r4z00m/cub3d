/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:48:24 by teusebio          #+#    #+#             */
/*   Updated: 2022/04/05 09:48:25 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	my_mlx_pixel_put(t_data *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->data + (y * img_data->line_length
			+ x * (img_data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	count_len(long tmp, int base, int *len)
{
	while (tmp > 0)
	{
		tmp /= base;
		(*len)++;
	}
}

char	*ft_itoa_base(long nbr, int base)
{
	long	tmp;
	int		len;
	char	*str;

	tmp = nbr;
	len = 0;
	if (nbr == 0)
		len++;
	count_len(tmp, base, &len);
	str = malloc(len + 1);
	str[len] = 0;
	while (len > 0)
	{
		str[len - 1] = nbr % base;
		if (nbr % base > 9)
			str[len - 1] += 'A' - 10;
		else
			str[len - 1] += '0';
		nbr /= base;
		len--;
	}
	return (str);
}
