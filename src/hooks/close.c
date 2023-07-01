/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/01 16:04:47 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/01 23:34:48 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	close_program(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->mlx)
		mlx_terminate(data->mlx);
	exit(0);
}
