/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 00:43:47 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/02 18:25:56 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "MLX42/MLX42.h"
# include "frctl_config.h"
# include "structs.h"
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"

/**
 * Generic
 */
void	throw_err(char *str, t_data *data);
t_data	init(t_data *data, char **av, int ac);
void	zoom(t_data *data);
void	init_color_palette(t_data *data);

/**
 *  Hooks
*/
void	key_hook(mlx_key_data_t kd, void *param);
void	render(void *param);
void	scroll_hook(double xdelta, double ydelta, void *param);
void	close_program(void *param);

/**
 * Mandelbrot
*/
void	mandelbrot(t_data *data);
double	iter_mandel(double x0, double y0);

/**
 * Julia
*/
void	julia(t_data *data);
double	iter_julia(double x0, double y0, t_data *data);

#endif
