/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/13 18:05:58 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/01 18:30:46 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static bool	in_bulb(double x0, double y0)
{
	double	q;
	double	p;
	double	x_shifted;

	q = (x0 - 0.25) * (x0 - 0.25) + y0 * y0;
	p = q * (q + (x0 - 0.25));
	if (p < 0.25 * y0 * y0)
		return (true);
	x_shifted = x0 + 1.0;
	if (x_shifted * x_shifted + y0 * y0 < 1.0 / 16.0)
		return (true);
	return (false);
}

static double	map_to_range(double value, double in_min, double in_max,
		t_cords out_range)
{
	return ((value - in_min) * (out_range.max - out_range.min) / (in_max
			- in_min) + out_range.min);
}

void	mandelbrot(t_data *d)
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
			if (!in_bulb(x0, y0))
			{
				d->iter = iter_mandel(x0, y0, d);
				if (d->iter < MAX_ITER)
					mlx_put_pixel(d->img, img_x, img_y, d->palette[d->iter
							% 256]);
				else
					mlx_put_pixel(d->img, img_x, img_y, d->palette[0]);
			}
			else
				mlx_put_pixel(d->img, img_x, img_y, d->palette[0]);
			img_y++;
		}
		img_x++;
	}
}
