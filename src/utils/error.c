/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/13 18:18:06 by mdekker       #+#    #+#                 */
/*   Updated: 2023/06/29 14:45:47 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

/**
 * @brief Prints an error message and exits the program
 *
 * @param str The error message to print
 */
void	err(char *str, t_data *data)
{
	ft_printf("Error: %s\n", str);
	if (data->mlx)
		mlx_terminate(data->mlx);
	exit(1);
}
