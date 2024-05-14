/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:08:38 by wtoumi            #+#    #+#             */
/*   Updated: 2024/05/14 04:43:26 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	handel_pixel(int x, int y, t_fractol *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (scale(x, 0, -2, 2) * fractal->zoom) + fractal->x_shift;
	z.y = (scale(y, 0, 2, -2) * fractal->zoom) + fractal->y_shift;
	c.x = fractal->c_r;
	c.y = fractal->c_i;
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = scale(i, 0, BLUE, TIFFANY);
			pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	pixel_put(x, y, &fractal->img, BLACK);
}

void	fractal_render_julia(t_fractol *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIDTH)
	{
		x = -1;
		while (++x < HEIGHT)
		{
			handel_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
