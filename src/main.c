/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/13 18:13:49 by mdekker       #+#    #+#                 */
/*   Updated: 2023/06/29 14:44:21 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	init(&data, av, ac);
	mlx_key_hook(data.mlx, &key_hook, &data);
	mlx_scroll_hook(data.mlx, &scroll_hook, &data);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
