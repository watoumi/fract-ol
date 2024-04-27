/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:50:55 by wtoumi            #+#    #+#             */
/*   Updated: 2024/04/27 20:47:55 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>


void    close_handler(t_fractol *fractol)
{
    mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
    mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
    free(fractol->mlx_connection);
    exit(EXIT_SUCCESS);
}
int keyhook(int key, t_fractol *fractol) {
  if (key == KEY_ARR_DOWN) {
    fractol->y_shift -= (ARROW_SENSITIVITY * fractol->zoom);
  } else if (key == KEY_ARR_UP) {
    fractol->y_shift += (ARROW_SENSITIVITY * fractol->zoom);

  } else if (key == KEY_ARR_LEFT) {
    fractol->x_shift -= (ARROW_SENSITIVITY * fractol->zoom);

  } else if (key == KEY_ARR_RIGHT) {
    fractol->x_shift += (ARROW_SENSITIVITY * fractol->zoom);
  }
  else if (key == KEY_PLUS)
  {
    fractol->iterations_definition += 10;
  }
  else if (key == KEY_MINES)
  {
    fractol->iterations_definition -= 10;
  }
  else if (key == KEY_SPACE)
  {
    close_handler(fractol);
  }
  printf("%d\n", key);
  return 0;
}

int mouse_handler(int button,int x, int y ,t_fractol *fractol)
{
  if (button == SCROLL_UP)
  {
    fractol->zoom *= 0.95;

  }
  else if (button == SCROLL_DOWN)
  {
    fractol->zoom *= 1.05;
  }
  fractol_render(fractol);
  return (0);
}
