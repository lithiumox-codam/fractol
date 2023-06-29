/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 01:18:50 by mdekker       #+#    #+#                 */
/*   Updated: 2023/06/29 12:29:40 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static double	map_to_range(int x, int min, int max, t_cords cords)
{
	double	percentage;

	percentage = (double)x / (double)WIDTH;
	if (cords.min == 0 && cords.max == 0)
		return (percentage * (max - min) + min);
	return (percentage * (cords.max - cords.min) + cords.min);
}

void	julia(t_data *d)
{
	int		img_x;
	int		img_y;
	double	x0;
	double	y0;

	img_x = 0;
	while (img_x < WIDTH)
	{
		img_y = 0;
		while (img_y < HEIGHT)
		{
			x0 = map_to_range(img_x, 0, WIDTH, d->x);
			y0 = map_to_range(img_y, 0, HEIGHT, d->y);
			d->iter = iter_julia(x0, y0, d);
			mlx_put_pixel(d->img, img_x, img_y, d->palette[d->iter % 256]);
			img_y++;
		}
		img_x++;
	}
}
