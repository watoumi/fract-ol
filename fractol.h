/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:54:04 by wtoumi            #+#    #+#             */
/*   Updated: 2024/05/14 05:22:25 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "/usr/local/include/mlx.h"
# include <ctype.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

# define ARROW_SENSITIVITY 0.1f

# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define KEY_ESC 53
# define KEY_ARR_UP 126
# define KEY_ARR_DOWN 125
# define KEY_ARR_RIGHT 123
# define KEY_ARR_LEFT 124
# define KEY_PLUS 69
# define KEY_MINES 78
# define KEY_X 17

# define BLACK 0
# define RED 0x00ff0000
# define GREEN 0x0000ff00
# define BLUE 0x000000ff
# define WHITE 0x00ffffff
# define TIFFANY 0x007CDEDC
# define SAGE 0x00B5B682
# define ORANGE 0x00FF851A
# define GHOZ 0x00FF38E1
# define GHOZ_FATEH 0x00D1417D
# define HEJRI 0x00744C5D
# define BLUE_FATEH 0X00067CC6
# define ORANGE_GHALEQ 0X00A77200

typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct s_img
{
	void		*img_ptr;
	char		*pixels_ptr;
	int			bpp;
	int			endian;
	int			line_len;
}				t_img;

typedef struct s_fractol
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_img		img;
	double		escape_value;
	int			iterations_definition;
	double		zoom;
	int			color;
	double		julia_x;
	double		julia_y;
	long double	x_shift;
	long double	y_shift;
	double		c_r;
	double		c_i;
	int			set;
}				t_fractol;

t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		square_complex(t_complex z);

void			fractol_render_mandelbrot(t_fractol *fractol);
void			fractal_render_julia(t_fractol *fractal);
void			handle_invalid_input(char **av, int index, int i);
void			check_julia(char **av, int index);

void			fractal_init(t_fractol *fractal);

void			handle_mandelbrot(char **av);

int				ft_strcmp(char *s1, char *s2);
double			ft_atof(char *str);

int				close_handler(t_fractol *fractol);
int				mouse_handler(int button, int x, int y, t_fractol *fractol);
int				key_handler(int keycode, t_fractol *fractol);
double			scale(int value, int oldmin, int newmin, int newmax);
int				ft_isdigit(int c);

#endif
