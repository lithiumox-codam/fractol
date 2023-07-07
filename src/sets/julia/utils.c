/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 15:00:19 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/07 10:30:16 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Calculates the new x and y values
 *
 * @param x0 The x coordinate of the pixel
 * @param y0 The y coordinate of the pixel
 * @param c_r The real part of the constant
 * @param c_i The imaginary part of the constant
 */
static void	calculate_new_values(double *x0, double *y0, double c_r, double c_i)
{
	double	x;
	double	y;

	x = *x0;
	y = *y0;
	*x0 = x * x - y * y + c_r;
	*y0 = 2 * x * y + c_i;
}

/**
 * @brief Checks if the current x and y values are the same as the last ones
 *
 * @param x0 The x coordinate of the pixel
 * @param y0 The y coordinate of the pixel
 * @param last_x The last x coordinate of the pixel
 * @param last_y The last y coordinate of the pixel
 * @return true If the current x and y values are the same as the last ones
 * @return false If the current x and y values are not the same as the last ones
 */
static bool	check_cycle(double x0, double y0, double *last_x, double *last_y)
{
	if (x0 == *last_x && y0 == *last_y)
		return (true);
	*last_x = x0;
	*last_y = y0;
	return (false);
}

/**
 * @brief Calculates the number of iterations needed to escape the julia set
 *
 * @param x0 The x coordinate of the pixel
 * @param y0 The y coordinate of the pixel
 * @param data The data struct
 * @return double The number of iterations needed to escape the julia set
 */
double	iter_julia(double x0, double y0, t_data *data)
{
	double	iteration;
	double	last_x;
	double	last_y;
	double	mag_sq;

	iteration = -1;
	last_x = x0;
	last_y = y0;
	while (iteration++ < ITER)
	{
		mag_sq = x0 * x0 + y0 * y0;
		if (mag_sq > 4.0)
			break ;
		calculate_new_values(&x0, &y0, data->complex.r, data->complex.i);
		if (check_cycle(x0, y0, &last_x, &last_y))
			return (ITER);
	}
	return (iteration);
}
