/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:19:25 by wtoumi            #+#    #+#             */
/*   Updated: 2024/05/14 04:38:41 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	scale(int value, int oldmin, int newmin, int newmax)
{
	double	new;

	new = (((double)(value - oldmin) / (800 - oldmin)) * (newmax - newmin))
		+ newmin;
	return (new);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

int	ft_isdigit(int c)
{
	return (c >= 0 && c <= 9);
}

double	ft_atof(char *str)
{
	double	exponent;
	double	fraction;
	char	*c;
	double	s;
	int		len;

	s = 1;
	c = str;
	if (str[0] == '-' && str[1] == '0')
		s = -1;
	exponent = (double)atoi(c);
	if (str[0] == '.')
		exponent = 0.0;
	while (c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	fraction = (double)atoi(c);
	len = strlen(c) + 1;
	while (--len != 0)
		fraction /= 10;
	if (exponent >= 0)
		return (s * (exponent + fraction));
	return (s * (exponent - fraction));
}
