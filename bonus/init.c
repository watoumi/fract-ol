/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 02:00:00 by wtoumi            #+#    #+#             */
/*   Updated: 2024/05/14 05:18:22 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

static void	malloc_error(void)
{
	write(1, "malloc failed\n", 14);
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations_definition = 43;
	fractol->zoom = 1.0;
}

static void	events_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_window, 04, 1L << 0, mouse_handler, fractol);
	mlx_hook(fractol->mlx_window, 17, 0, &close_handler, fractol);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	fractol->x_shift = 0;
	fractol->y_shift = 0;
	if (NULL == fractol->mlx_connection)
		malloc_error();
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, WIDTH, HEIGHT,
			fractol->name);
	if (NULL == fractol->mlx_window)
	{
		free(fractol->mlx_connection);
		malloc_error();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection, WIDTH,
			HEIGHT);
	if (NULL == fractol->img.img_ptr)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		free(fractol->mlx_connection);
		malloc_error();
	}
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp, &fractol->img.line_len, &fractol->img.endian);
	events_init(fractol);
	data_init(fractol);
}
