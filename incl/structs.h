/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 00:41:13 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/02 18:26:11 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "frctl_config.h"
# include <fractol.h>

/**
 * @brief The fractal sets
 *
 * @param MANDELBROT The mandelbrot set
 * @param JULIA The julia set
 */
typedef enum e_sets
{
	MANDELBROT,
	JULIA
}				t_sets;

/**
 * @brief The color offset struct
 *
 * @param r_o The red offset
 * @param g_o The green offset
 * @param b_o The blue offset
 */
typedef struct s_color
{
	double		r_o;
	double		g_o;
	double		b_o;
}				t_color;
/**
 * @brief The coordinates of a point
 *
 * @param min The minimum value
 * @param max The maximum value
 */
typedef struct s_cords
{
	double		min;
	double		max;
}				t_cords;

/**
 * @brief The zoom level
 *
 * @param x The x coordinate of the zoom point
 * @param y The y coordinate of the zoom point
 * @param factor The zoom factor
 */
typedef struct s_zoom
{
	double		x;
	double		y;
	double		factor;
	double		level;
}				t_zoom;

/**
 * @brief The mouse position
 *
 * @param x The x coordinate
 * @param y The y coordinate
 */
typedef struct s_mouse
{
	int32_t		x;
	int32_t		y;
}				t_mouse;

/**
 * @brief
 *
 * This struct is used to track changes in the fractal. If there has been a
 * change, the fractal will be rendered again. This is to prevent the fractal
 * from being rendered every frame.
 *
 * @example If the user changes the color, the fractal will be rendered again
 *
 * @param frames The number of frames to wait before rendering
 * @param changed Whether there has been a change by the user
 */
typedef struct s_renderer
{
	int			frames;
	bool		changed;
}				t_renderer;

/**
 * @brief The complex number struct
 *
 * @param r The real part
 * @param i The imaginary part
 */
typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

/**
 * @brief The main data struct
 *
 * @param mlx The MLX42 struct
 * @param img The image struct
 * @param frctl The fractal to be drawn
 * @param iter The maximum number of iterations
 * @param x Struct containing the x range
 * @param y Struct containing the y range
 * @param c The complex number (used in julia set)
 * @param mouse The mouse position
 * @param zoom The zoom level
 * @param renderer The render struct to track changes
 * @param palette The color palette (precalculated)
 */
typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_sets		frctl;
	u_int32_t	iter;
	t_cords		x;
	t_cords		y;
	t_complex	complex;
	t_zoom		zoom;
	t_mouse		mouse;
	t_renderer	renderer;
	t_color		color;
	uint32_t	palette[MAX_ITER];
}				t_data;

#endif
