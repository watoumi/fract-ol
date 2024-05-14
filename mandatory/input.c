/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:50:55 by wtoumi            #+#    #+#             */
/*   Updated: 2024/05/14 04:47:20 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	exit(0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 5)
		fractol->zoom *= 0.95;
	else if (button == 4)
		fractol->zoom *= 1.05;
	if (fractol->set == 1)
		fractol_render_mandelbrot(fractol);
	else if (fractol->set == 2)
		fractal_render_julia(fractol);
	return (0);
}

static void	handel_pan(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ARR_LEFT)
		fractol->x_shift += (0.5 * fractol->zoom);
	else if (keycode == KEY_ARR_RIGHT)
		fractol->x_shift -= (0.5 * fractol->zoom);
	else if (keycode == KEY_ARR_UP)
		fractol->y_shift += (0.5 * fractol->zoom);
	else if (keycode == KEY_ARR_DOWN)
		fractol->y_shift -= (0.5 * fractol->zoom);
}

int	key_handler(int keycode, t_fractol *fractol)
{
	if (keycode == 49)
		fractol->color += 100;
	else if (keycode == KEY_ESC)
		close_handler(fractol);
	else if (keycode == KEY_PLUS)
		fractol->iterations_definition += 42;
	else if (keycode == KEY_MINES)
		fractol->iterations_definition -= 42;
	else if (keycode == 18)
		fractol->iterations_definition += 10;
	else if (keycode == 19)
		fractol->iterations_definition -= 10;
	else
		handel_pan(keycode, fractol);
	if (fractol->set == 1)
		fractol_render_mandelbrot(fractol);
	else if (fractol->set == 2)
		fractal_render_julia(fractol);
	return (0);
}
