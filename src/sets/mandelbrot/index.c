/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/13 18:05:58 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/07 10:41:31 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief A local struct to store the x and y coordinates of the pixel
 */
typedef struct s_img
{
	int			x;
	int			y;
	double		x0;
	double		y0;
}				t_img;

/**
 * @brief A function that maps a value to a range
 *
 * @param x0 The x value to map
 * @param y0 The y value to map
 * @return true If the point is in the primary and secondary bulb
 * @return false If the point is not in the primary and secondary bulb
 */
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

/**
 * @brief A function that maps a value to a range
 *
 * @param value The value to map
 * @param in_min The minimum value of the range
 * @param in_max The maximum value of the range
 * @param out_range The range to map to
 * @return double The mapped value
 */
static double	map_to_range(double value, double in_min, double in_max,
		t_cords out_range)
{
	return ((value - in_min) * (out_range.max - out_range.min) / (in_max
			- in_min) + out_range.min);
}

/**
 * @brief The wrapper function for the mandelbrot set
 *
 * @param d The data struct
 */
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
			if (d->iter < ITER)
				mlx_put_pixel(d->img, img.x, img.y, d->palette[d->iter % ITER]);
			else
				mlx_put_pixel(d->img, img.x, img.y, d->palette[0]);
			img.y++;
		}
		img.x++;
	}
}
