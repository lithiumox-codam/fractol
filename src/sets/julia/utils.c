/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 15:00:19 by mdekker       #+#    #+#                 */
/*   Updated: 2023/06/29 12:37:35 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static double	calculate_iterations(t_data *data)
{
	double	max_iter;

	max_iter = data->zoom.level * 50;
	if (max_iter < 1)
		max_iter = 1;
	return (max_iter);
}

static void	calculate_new_values(double *x0, double *y0, double c_r, double c_i)
{
	double	x;
	double	y;

	x = *x0;
	y = *y0;
	*x0 = x * x - y * y + c_r;
	*y0 = 2 * x * y + c_i;
}

static bool	check_cycle(double x0, double y0, double *last_x, double *last_y)
{
	if (x0 == *last_x && y0 == *last_y)
		return (true);
	*last_x = x0;
	*last_y = y0;
	return (false);
}

double	iter_julia(double x0, double y0, t_data *data)
{
	double	iteration;
	double	last_x;
	double	last_y;
	double	mag_sq;
	double	max_iter;

	max_iter = calculate_iterations(data);
	iteration = -1;
	last_x = x0;
	last_y = y0;
	while (iteration++ < max_iter)
	{
		mag_sq = x0 * x0 + y0 * y0;
		if (mag_sq > 4.0)
			break ;
		calculate_new_values(&x0, &y0, data->complex.r, data->complex.i);
		if (check_cycle(x0, y0, &last_x, &last_y))
			return (MAX_ITER);
	}
	return (iteration);
}