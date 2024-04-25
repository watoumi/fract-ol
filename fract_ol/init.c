/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:21:22 by wtoumi            #+#    #+#             */
/*   Updated: 2024/04/25 17:01:02 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// static void	malloc_error(void)
// {
// 	printf("Problems with malloc");
// 	exit(EXIT_FAILURE);
// }

static void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations_definition = 42;
}

// static void	events_init(t_fractol *fractol)
// {
// 	mlx_hook(fractol->mlx_window, 02, 1L<<0, key_handler, fractol);
// 	//mlx_hook(fractol->mlx_window, ButtonPress, ButtonPressMask, mouse_handler, fractol);
// 	//mlx_hook(fractol->mlx_window, DestroyNotify, StructureNotifyMask, close_handler, fractol);
// }

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	// if (NULL == fractol->mlx_connection)
	// 	malloc_error();
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection,
										WIDTH,
										HEIGHT,
										fractol->name);
	if (NULL == fractol->mlx_window)
	{
		//mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		// malloc_error();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection,
										WIDTH, HEIGHT);
	// if (NULL == fractol->img.img_ptr)
	// {
	// 	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	// 	//mlx_destroy_display(fractol->mlx_connection);
	// 	free(fractol->mlx_connection);
	// 	malloc_error();
	// }
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
												&fractol->img.bpp,
												&fractol->img.line_len,
												&fractol->img.endian);
	// events_init(fractol);
	data_init(fractol);
}
