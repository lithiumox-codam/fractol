/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 16:43:22 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/01 16:03:18 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Determine which fractol to render.
 *
 * @param data The data struct.
 */
static void	determine_fractol(t_data *data)
{
	if (data->frctl == MANDELBROT)
		mandelbrot(data);
	else if (data->frctl == JULIA)
		julia(data);
}

void	render(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->renderer.frames < FRAME_WAIT)
	{
		data->renderer.frames++;
		return ;
	}
	data->renderer.frames = 0;
	if (data->renderer.changed)
		determine_fractol(data);
	data->renderer.changed = false;
}
