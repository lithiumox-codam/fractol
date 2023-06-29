/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/27 00:41:13 by mdekker       #+#    #+#                 */
/*   Updated: 2023/06/29 12:36:46 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <fractol.h>

/**
 * @brief Colors used in the fractals
 *
 * RGB values are stored in an array of 3 ints
 * @param R Red
 * @param G Green
 * @param B Blue
 */
typedef enum e_colors
{
	R,
	G,
	B
}				t_colors;

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
 * @brief The renderer struct
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
 * @param color The color to be used
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
	t_colors	color[3];
	t_cords		x;
	t_cords		y;
	t_complex	complex;
	t_zoom		zoom;
	t_mouse		mouse;
	t_renderer	renderer;
	uint32_t	palette[256];
}				t_data;

#endif
