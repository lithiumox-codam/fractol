/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scroll.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 00:37:00 by mdekker       #+#    #+#                 */
/*   Updated: 2023/06/29 14:37:52 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	update_mouse_pos(t_data *data)
{
	int32_t	x;
	int32_t	y;

	mlx_get_mouse_pos(data->mlx, &x, &y);
	if (x < 0)
		x = 0;
	else if (x > data->mlx->width)
		x = data->mlx->width;
	if (y < 0)
		y = 0;
	else if (y > data->mlx->height)
		y = data->mlx->height;
	data->mouse.x = x;
	data->mouse.y = y;
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	(void)xdelta;
	data = (t_data *)param;
	if (ydelta > 0)
		data->zoom.factor = 1.1;
	else
		data->zoom.factor = 1 / 1.1;
	data->zoom.level += data->zoom.factor - 1;
	update_mouse_pos(data);
	zoom(data);
	data->renderer.changed = true;
}
