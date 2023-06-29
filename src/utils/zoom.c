/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zoom.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/14 22:13:49 by mdekker       #+#    #+#                 */
/*   Updated: 2023/06/18 02:07:00 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	update_range(t_cords *range, double center, double factor)
{
	double	width;
	double	new_width;

	width = range->max - range->min;
	new_width = width / factor;
	range->min = center - (new_width * ((center - range->min) / width));
	range->max = range->min + new_width;
}

/**
 * @brief Zoom in on the mouse position
 * 
 * I take the mouse position as a percentage of the screen width and height.
 * I then use that percentage to calculate the position of the mouse in the
 * fractal. I then use that position to zoom in on the fractal.
 * 
 * @param data The data struct
 */
void	zoom(t_data *data)
{
	data->zoom.x = data->x.min + (data->x.max - data->x.min) * (data->mouse.x
			/ (double)data->mlx->width);
	data->zoom.y = data->y.min + (data->y.max - data->y.min) * (data->mouse.y
			/ (double)data->mlx->height);
	update_range(&data->x, data->zoom.x, data->zoom.factor);
	update_range(&data->y, data->zoom.y, data->zoom.factor);
}
