/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 02:04:31 by wtoumi            #+#    #+#             */
/*   Updated: 2024/05/14 04:18:22 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

long double	map(long double x, long double x_max, long double out_max,
		long double out_min)
{
	return (((x / x_max) * (out_max - out_min)) + out_min);
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

	result.x = fabs(z.x * z.x) - fabs(z.y * z.y);
	result.y = 2 * fabs(z.x * z.y);
	return (result);
}
