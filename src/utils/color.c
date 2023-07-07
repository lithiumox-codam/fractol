/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 02:00:56 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/07 10:41:41 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Initialize the color palette
 *
 * by using the formulas from https://krazydad.com/tutorials/makecolors.php
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
	data->palette[0] = 0xAA;
	while (i < ITER)
	{
		t = (double)i / (ITER / 2);
		r = (int)(data->color.r_o * (1 - t) * t * t * t * 255);
		g = (int)(data->color.g_o * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(data->color.b_o * (1 - t) * (1 - t) * (1 - t) * t * 255);
		data->palette[i] = (r << 24) | (g << 16) | (b << 8) | 255;
		i++;
	}
}
