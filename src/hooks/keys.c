/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/14 22:08:09 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/08 14:26:19 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Move the fractal in the x direction
 *
 * and limit it to the range of the fractal so when zoomed in
 * the fractal is less likely to move out of view
 *
 * @param data The data struct
 * @param amount The amount to move
 */
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

/**
 * @brief Move the fractal in the y direction
 *
 * and limit it to the range of the fractal so when zoomed in
 * the fractal is less likely to move out of view
 *
 * @param data The data struct
 * @param amount The amount to move
 */
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

static void	reset_cords(t_data *data)
{
	data->x.min = -2;
	data->x.max = 2;
	data->y.min = -2;
	data->y.max = 2;
	data->zoom.factor = 1;
	data->zoom.x = 0;
	data->zoom.y = 0;
	data->color.r_o = 9;
	data->color.g_o = 15;
	data->color.b_o = 8.5;
	init_color_palette(data);
}

void	extra_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE))
		shift_palette(data);
}

/**
 * @brief The key hook
 *
 * @param kd The key data
 * @param param The data struct
 */
void	key_hook(mlx_key_data_t kd, void *param)
{
	t_data	*data;

	(void)kd;
	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		move_y(data, -0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		move_y(data, 0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		move_x(data, 0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		move_x(data, -0.1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_TAB))
	{
		if (data->frctl == JULIA)
			data->frctl = MANDELBROT;
		else
			data->frctl = JULIA;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_R))
		reset_cords(data);
	extra_keys(data);
	data->renderer.changed = true;
}
