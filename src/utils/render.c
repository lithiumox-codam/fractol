/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 16:43:22 by mdekker       #+#    #+#                 */
/*   Updated: 2023/06/29 12:30:06 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	calculate_frame_wait(t_data *data)
{
	double	zoom_level;
	int		frame_wait;

	zoom_level = data->zoom.level - 1;
	if (zoom_level < 0)
		zoom_level = 0;
	frame_wait = (int)(20 * log(zoom_level + 1) + 1);
	if (frame_wait < 1)
		frame_wait = 1;
	return (frame_wait);
}

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
	int		frame_wait;

	data = (t_data *)param;
	frame_wait = calculate_frame_wait(data);
	if (data->renderer.frames < frame_wait)
	{
		data->renderer.frames++;
		return ;
	}
	data->renderer.frames = 0;
	if (data->renderer.changed)
		determine_fractol(data);
	data->renderer.changed = false;
}
