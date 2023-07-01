/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 02:00:56 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/01 16:02:13 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Initialize the color palette
 *
 * by using the formula from https://krazydad.com/tutorials/makecolors.php
 *
 * @param data The data struct
 */
void	init_color_palette(t_data *data)
{
	int		i;
	double	t;
	int		r;
	int		g;
	int		b;

	i = 1;
	data->palette[0] = 0x000000;
	while (i < 256)
	{
		t = (double)i / (256 / 2);
		r = (int)(9 * (1 - t) * t * t * t * 255);
		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		data->palette[i] = (r << 24) | (g << 16) | (b << 8) | 255;
		i++;
	}
}
