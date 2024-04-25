/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:54:04 by wtoumi            #+#    #+#             */
/*   Updated: 2024/04/25 16:41:45 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stddef.h>
# include "/usr/local/include/mlx.h"



#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\" ./fractol julia <value_1 <value_2\""
#define WIDTH 800
#define HEIGHT 800


#define Black           0x0000
#define Navy            0x000F
#define DarkGreen       0x03E0
#define DarkCyan        0x03EF
#define Maroon          0x7800
#define Purple          0x780F
#define Olive           0x7BE0
#define LightGrey       0xC618
#define DarkGrey        0x7BEF
#define Green           0x07E0
#define Cyan            0x07FF
#define Red             0xF800
#define Magenta         0xF81F
#define Yellow          0xFFE0
#define White           0xFFFF
#define Orange          0xFD20
#define GreenYellow     0xAFE5
#define Pink            0xF81F



typedef struct s_complex
{
    long double x;
    long double y;
}           t_complex;

typedef struct s_img
{
    void *img_ptr;
    char *pixels_ptr;
    int  bpp;
    int endian;
    int line_len;
}           t_img;

typedef struct s_fractol
{
    char *name;
    void *mlx_connection;
    void *mlx_window;
    t_img img;
    double escape_value;
    int iterations_definition;
}           t_fractol;


//  strings utils

int ft_strncmp(char *s1, char *s2, int n);
void putstr_fd(char *s, int fd);

void fractol_init(t_fractol *fractol);
// static	void malloc_error(void);
void fractol_init(t_fractol *fractol);
int fractol_render(t_fractol *fractol);
double map(long x, long in_min, long in_max, long out_min, long out_max);
t_complex   square_complex(t_complex z);
t_complex  sum_complex(t_complex z1, t_complex z2);
void handle_pixel(int x, int y, t_fractol *fractol);
// int key_handler(int keysym, t_fractol *fractol);
//static void	data_init(t_fractol *fractol);
// static void	events_init(t_fractol *fractol);


#endif
