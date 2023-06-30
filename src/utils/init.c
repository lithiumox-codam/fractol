/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/13 18:44:45 by mdekker       #+#    #+#                 */
/*   Updated: 2023/06/30 02:14:34 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	construct(t_data *data)
{
	data->x.min = -2.0;
	data->x.max = 1.5;
	data->y.min = -1.5;
	data->y.max = 2.0;
	data->color[R] = 1;
	data->color[G] = 1;
	data->color[B] = 1;
	data->zoom.factor = 1.0;
	data->zoom.level = 3;
	data->renderer.changed = true;
	data->renderer.frames = 20;
	if (data->frctl == MANDELBROT)
	{
		data->complex.r = -0.7;
		data->complex.i = 0.27015;
	}
}

static void	parse_argv(int ac, char **av, t_data *data)
{
	if (ac == 1)
		err("Usage -> ./fractol [fractal] [constant (optional)]", data);
	if (ft_strcmp(av[1], "mandelbrot") == 0 && ac == 2)
		data->frctl = MANDELBROT;
	else if (ft_strcmp(av[1], "julia") == 0 && ac == 3)
	{
		data->frctl = JULIA;
		data->complex.r = ft_atod(av[2]);
		data->complex.i = ft_atod(av[3]);
	}
	else
		err("Usage: ./fractol [fractal] [constant (optional)]", data);
	ft_printf("%d\n", __LINE__);
	ft_printf("Fractal: %d\n", data->frctl);
	construct(data);
	init_color_palette(data);
}

static void	start_mlx(mlx_t *mlx, t_data *data)
{
	if (!mlx)
		err("mlx_init failed", data);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_set_setting(MLX_FULLSCREEN, true);
	data->mlx = mlx;
	data->img = mlx_new_image(mlx, WIDTH, HEIGHT);
}

t_data	init(t_data *data, char **av, int ac)
{
	parse_argv(ac, av, data);
	start_mlx(mlx_init(WIDTH, HEIGHT, "Fractol", true), data);
	return (*data);
}
