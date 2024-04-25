/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:13:16 by wtoumi            #+#    #+#             */
/*   Updated: 2024/04/25 17:07:27 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static void my_pixel_put(int x , int y, t_img *img, int color)
{
    int ofsset;

    ofsset = (y * img->line_len) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels_ptr + ofsset) = color;
}


void handle_pixel(int x, int y, t_fractol *fractol)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    z.x = 0.0;
    z.y = 0.0;
    i = 0;

    c.x = map(x, -2, 2, 0, WIDTH);
    c.y = map(y, -2, 2, 0, HEIGHT);
    while (i < fractol->iterations_definition)
    {
        z = sum_complex(square_complex(z), c);
        if((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
        {

            color = map(i, Yellow, White, 0, fractol->iterations_definition);

            my_pixel_put(x, y, &fractol->img, Yellow);
            return;
        }
        i++;
    }
    my_pixel_put(x, y, &fractol->img, GreenYellow);
}

int fractol_render(t_fractol *fractol)
{
    int x;
    int y;
    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            handle_pixel(x, y, fractol);
        }
    }
    mlx_put_image_to_window(fractol->mlx_connection,fractol->mlx_window , fractol->img.img_ptr,0, 0);
    mlx_loop(fractol);
    return 0;
}
