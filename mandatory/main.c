/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:50:57 by wtoumi            #+#    #+#             */
/*   Updated: 2024/05/14 04:47:08 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	handle_mandelbrot(char **av)
{
	t_fractol	fractol;

	fractol.set = 1;
	fractol.name = av[1];
	fractal_init(&fractol);
	fractol_render_mandelbrot(&fractol);
	mlx_loop(fractol.mlx_connection);
}

void	handle_julia(char **av, int ac)
{
	t_fractol	fractol;

	fractol.set = 2;
	fractol.name = av[1];
	if (ac == 2)
	{
		fractol.c_r = -0.4;
		fractol.c_i = 0.6;
	}
	else
	{
		fractol.c_r = ft_atof(av[2]);
		fractol.c_i = ft_atof(av[3]);
	}
	fractal_init(&fractol);
	fractal_render_julia(&fractol);
	mlx_loop(fractol.mlx_connection);
}

int	main(int ac, char **av)
{
	if (ac == 2 && ft_strcmp(av[1], "mandelbrot"))
		handle_mandelbrot(av);
	else if ((ac == 4 || ac == 2) && ft_strcmp(av[1], "julia"))
	{
		if (ac == 4)
		{
			check_julia(av, 2);
			check_julia(av, 3);
		}
		handle_julia(av, ac);
	}
	else
	{
		write(1, "please enter mandelbrot or julia\n", 50);
		exit(1);
	}
	return (0);
}
