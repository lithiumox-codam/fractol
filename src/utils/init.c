/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/13 18:44:45 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/06 16:35:37 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	construct(t_data *data)
{
	data->x.min = -2;
	data->x.max = 2;
	data->y.min = -2;
	data->y.max = 2;
	data->zoom.factor = 1.0;
	data->renderer.changed = true;
	data->renderer.frames = FRAME_WAIT;
	data->color.r_o = 9;
	data->color.g_o = 15;
	data->color.b_o = 8.5;
	if (data->frctl == MANDELBROT)
	{
		data->complex.r = -0.7;
		data->complex.i = 0.27015;
	}
}

static void	parse_argv(int ac, char **av, t_data *data)
{
	if (ac == 1)
		throw_err("Usage -> ./fractol [fractal] [r] [i]", data);
	if (ft_strcmp(av[1], "mandelbrot") == 0 && ac == 2)
		data->frctl = MANDELBROT;
	else if (ft_strcmp(av[1], "julia") == 0 && ac == 4)
	{
		data->frctl = JULIA;
		data->complex.r = ft_atod(av[2]);
		data->complex.i = ft_atod(av[3]);
		if (data->complex.r < -2.0 || data->complex.r > 2.0
			|| data->complex.i > 2.0 || data->complex.i < -2.0)
			throw_err("Please provide numbers between -2 & 2", data);
	}
	else
		throw_err("Usage: ./fractol [fractal] [r] [i]", data);
	construct(data);
	init_color_palette(data);
}

static void	start_mlx(mlx_t *mlx, t_data *data)
{
	if (!mlx)
		throw_err("mlx_init failed", data);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx = mlx;
	data->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!data->img)
		throw_err("mlx_new_image failed", data);
}

t_data	init(t_data *data, char **av, int ac)
{
	ft_bzero(data, sizeof(t_data));
	parse_argv(ac, av, data);
	start_mlx(mlx_init(WIDTH, HEIGHT, "Fractol", true), data);
	return (*data);
}
