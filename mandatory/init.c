/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:21:22 by wtoumi            #+#    #+#             */
/*   Updated: 2024/05/14 04:47:37 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	data_init(t_fractol *fractal)
{
	fractal->iterations_definition = 50;
	fractal->escape_value = 4;
	fractal->zoom = 1.0;
	fractal->x_shift = 0.0;
	fractal->y_shift = 0.0;
	fractal->color = WHITE;
}

static void	events_init(t_fractol *fractal)
{
	mlx_hook(fractal->mlx_window, 17, 0, close_handler, fractal);
	mlx_mouse_hook(fractal->mlx_window, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, 02, 1L << 0, key_handler, fractal);
}

void	fractal_init(t_fractol *fractal)
{
	fractal->mlx_connection = NULL;
	fractal->mlx_window = NULL;
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		exit(1);
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, WIDTH);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		exit(1);
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	data_init(fractal);
	events_init(fractal);
}
