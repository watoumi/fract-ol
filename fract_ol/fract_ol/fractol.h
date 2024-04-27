/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:54:04 by wtoumi            #+#    #+#             */
/*   Updated: 2024/04/27 21:35:12 by wtoumi           ###   ########.fr       */
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
#define WIDTH 920
#define HEIGHT 920

#define ARROW_SENSITIVITY 0.1f

# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define KEY_ESC 53
# define KEY_ARR_UP 126
# define KEY_ARR_DOWN 125
# define KEY_ARR_RIGHT 123
# define KEY_ARR_LEFT 124
# define KEY_PLUS 69
# define KEY_MINES 78

#define BLACK   0
#define RED     0x00ff0000
#define GREEN   0x0000ff00
#define BLUE    0x000000ff
#define WHITE   0x00ffffff
#define tiffany_blue 0x007CDEDC
# define SAGE   0x00B5B682
# define ORANGE 0x00FF851A
# define GHOZ   0x00FF38E1
# define GHOZ_FATEH 0x00D1417D
# define HEJRI  0x00744C5D
# define BLUE_FATEH 0X00067CC6
# define ORANGE_GHALEQ 0X00A77200

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
    double zoom;
    double julia_x;
    double julia_y;
    long double x_shift;
    long double y_shift;
}           t_fractol;


//  strings utils

int ft_strncmp(char *s1, char *s2, int n);
void putstr_fd(char *s, int fd);
int keyhook(int key, t_fractol *fractol);
void fractol_init(t_fractol *fractol);
void fractol_init(t_fractol *fractol);
int fractol_render(t_fractol *fractol);
long double map(long double x, long double x_max, long double out_max, long double out_min);
t_complex   square_complex(t_complex z);
t_complex  sum_complex(t_complex z1, t_complex z2);
void handle_pixel(int x, int y, t_fractol *fractol);
double atodbl(char *s);

void    close_handler(t_fractol *fractol);
int mouse_handler(int button,int x, int y ,t_fractol *fractol);


#endif
