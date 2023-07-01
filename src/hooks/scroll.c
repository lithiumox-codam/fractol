/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scroll.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 00:37:00 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/01 23:16:14 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Function to update the mouse position so the zoom can be centered
 *
 * @param data The data struct
 */
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

/**
 * @brief Zoom in or out on the fractal
 *
 * @param xdelta The amount to zoom in the x direction
 * @param ydelta The amount to zoom in the y direction
 * @param param The data struct
 */
void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->frctl == JULIA && mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
	{
		data->complex.i += xdelta / 1000;
		data->complex.r += xdelta / 1000;
		data->renderer.changed = true;
		return ;
	}
	if (ydelta > 0)
		data->zoom.factor = 1.1;
	else
		data->zoom.factor = 1 / 1.1;
	update_mouse_pos(data);
	zoom(data);
	data->renderer.changed = true;
}
