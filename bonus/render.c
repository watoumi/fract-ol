/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 02:05:58 by wtoumi            #+#    #+#             */
/*   Updated: 2024/05/14 04:43:18 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

static void	my_pixel_put(int x, int y, t_img *img, unsigned int color)
{
	int	ofsset;

	ofsset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(((unsigned char *)img->pixels_ptr) + ofsset) = color;
}

void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex		z;
	t_complex		c;
	int				i;
	unsigned int	color;
	double			tmp;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = (map(x, WIDTH, 2, -2) * fractol->zoom) + fractol->x_shift;
	c.y = (map(y, HEIGHT, 2, -2) * fractol->zoom) + fractol->y_shift;
	while (i < fractol->iterations_definition)
	{
		tmp = z.x * z.x - z.y * z.y + c.x;
		z.y = fabs(2 * z.x * z.y) + c.y;
		z.x = fabs(tmp);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = map(i, fractol->iterations_definition, BLUE, TIFFANY);
			my_pixel_put(x, y, &fractol->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractol->img, BLACK);
}

int	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window,
		fractol->img.img_ptr, 0, 0);
	return (0);
}
