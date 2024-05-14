/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 02:03:26 by wtoumi            #+#    #+#             */
/*   Updated: 2024/05/14 05:18:52 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac == 2 && !ft_strncmp(av[1], "burn", 4))
	{
		fractol.name = "burn";
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
