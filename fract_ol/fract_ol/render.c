/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:13:16 by wtoumi            #+#    #+#             */
/*   Updated: 2024/04/27 21:34:16 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void my_pixel_put(int x, int y, t_img *img, unsigned int color) {
  int ofsset;

  ofsset = (y * img->line_len) + (x * (img->bpp / 8));
  *(unsigned int *)(((unsigned char*)img->pixels_ptr) + ofsset) = color;
}

static void julia(t_complex *z, t_complex *c,t_fractol *fractol)
{
    if (!ft_strncmp(fractol->name, "julia", 5))
    {
      c->x = fractol->julia_x;
      c->y = fractol->julia_y;
    }
    else {
    c->x = z->x;
    c->y = z->y;
    }
}

void handle_pixel(int x, int y, t_fractol *fractol) {


  t_complex z;
  t_complex c;
  int i;
  unsigned int color;

  i = 0;
  z.x = (map(x, WIDTH, 2, -2 ) * fractol->zoom) + fractol->x_shift;
  z.y = (map(y, HEIGHT, 2, -2) * fractol->zoom) + fractol->y_shift;
  julia(&z, &c, fractol);
  while (i < fractol->iterations_definition)
  {
    z = sum_complex(square_complex(z), c);
    if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
    {
      color = map(i, fractol->iterations_definition, BLUE, ORANGE_GHALEQ);
      my_pixel_put(x, y, &fractol->img, color);
      return;
    }
    i++;
  }
  my_pixel_put(x, y, &fractol->img, BLACK);
}

  int fractol_render(t_fractol * fractol) {
    int x;
    int y;

    y = 0;
    while (y < HEIGHT) {
      x = 0;
      while (x < WIDTH) {
        handle_pixel(x, y, fractol);
        x++;
      }
      y++;
    }
    mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window,
                            fractol->img.img_ptr, 0, 0);
    return 0;
  }
