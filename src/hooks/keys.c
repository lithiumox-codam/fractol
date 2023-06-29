/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/14 22:08:09 by mdekker       #+#    #+#                 */
/*   Updated: 2023/06/29 12:35:06 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static bool	press(action_t action)
{
	if (action == MLX_PRESS)
		return (true);
	return (false);
}

static void	move_x(t_data *data, double amount)
{
	double	movement_factor;
	double	range_per_pixel;
	double	pixels_per_click;

	pixels_per_click = 250;
	range_per_pixel = (data->x.max - data->x.min) / WIDTH;
	movement_factor = 1.0 / (1.0 + pow(log10(data->zoom.factor), 2));
	movement_factor = fmin(movement_factor, pixels_per_click * range_per_pixel);
	data->x.min += amount * movement_factor;
	data->x.max += amount * movement_factor;
}

static void	move_y(t_data *data, double amount)
{
	double	movement_factor;
	double	range_per_pixel;
	double	pixels_per_click;

	pixels_per_click = 250;
	range_per_pixel = (data->y.max - data->y.min) / HEIGHT;
	movement_factor = 1.0 / (1.0 + pow(log10(data->zoom.factor), 2));
	movement_factor = fmin(movement_factor, pixels_per_click * range_per_pixel);
	data->y.min += amount * movement_factor;
	data->y.max += amount * movement_factor;
}

static int	wasd_arrow(mlx_key_data_t kd)
{
	if (kd.key == MLX_KEY_W || kd.key == MLX_KEY_UP)
		return (1);
	if (kd.key == MLX_KEY_S || kd.key == MLX_KEY_DOWN)
		return (2);
	if (kd.key == MLX_KEY_D || kd.key == MLX_KEY_RIGHT)
		return (3);
	if (kd.key == MLX_KEY_A || kd.key == MLX_KEY_LEFT)
		return (4);
	return (0);
}

void	key_hook(mlx_key_data_t kd, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (wasd_arrow(kd) == 1 && press(kd.action))
		move_y(data, -0.1);
	if (wasd_arrow(kd) == 2 && press(kd.action))
		move_y(data, 0.1);
	if (wasd_arrow(kd) == 3 && press(kd.action))
		move_x(data, 0.1);
	if (wasd_arrow(kd) == 4 && press(kd.action))
		move_x(data, -0.1);
	if (kd.key == MLX_KEY_ESCAPE && press(kd.action))
		mlx_close_window(data->mlx);
	if (kd.key == MLX_KEY_TAB && press(kd.action))
	{
		if (data->frctl == JULIA)
			data->frctl = MANDELBROT;
		else
			data->frctl = JULIA;
	}
	data->renderer.changed = true;
}
