/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:50:57 by wtoumi            #+#    #+#             */
/*   Updated: 2024/04/27 21:34:30 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{

	t_fractol	fractol;


	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)) ||
    (4 == ac && !ft_strncmp(av[1], "julia", 5)))

	{
		fractol.name = av[1];
		if (!ft_strncmp(fractol.name, "julia", 5))
		{
			fractol.julia_x = atodbl(av[2]);
			fractol.julia_y = atodbl(av[3]);
		}
		fractol_init(&fractol);

		fractol_render(&fractol);
		mlx_key_hook(fractol.mlx_window, keyhook, &fractol);
		mlx_loop_hook(fractol.mlx_connection, fractol_render, &fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
