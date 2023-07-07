/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/13 18:18:06 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/07 10:37:28 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Prints an error message and exits the program
 *
 * @param str The error message to print
 */
void	throw_err(char *str, t_data *data)
{
	ft_printf("Error: %s\n", str);
	ft_printf("Possible sets: mandelbrot, julia\n");
	if (data->mlx)
	{
		mlx_close_window(data->mlx);
		mlx_terminate(data->mlx);
	}
	exit(1);
}
