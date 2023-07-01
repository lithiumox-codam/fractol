/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/13 18:05:58 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/02 00:58:19 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

typedef struct s_img
{
	int			x;
	int			y;
	double		x0;
	double		y0;
}				t_img;

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
	t_img	img;

	img.x = 0;
	while (img.x < WIDTH)
	{
		img.y = 0;
		while (img.y < HEIGHT)
		{
			img.x0 = map_to_range(img.x, 0, WIDTH, d->x);
			img.y0 = map_to_range(img.y, 0, HEIGHT, d->y);
			if (in_bulb(img.x0, img.y0))
			{
				mlx_put_pixel(d->img, img.x, img.y, d->palette[0]);
				img.y++;
				continue ;
			}
			d->iter = iter_mandel(img.x0, img.y0);
			if (d->iter < MAX_ITER)
				mlx_put_pixel(d->img, img.x, img.y, d->palette[d->iter % 256]);
			else
				mlx_put_pixel(d->img, img.x, img.y, d->palette[0]);
			img.y++;
		}
		img.x++;
	}
}
