/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:19:25 by wtoumi            #+#    #+#             */
/*   Updated: 2024/04/27 15:37:53 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double map(long double x, long double x_max, long double out_max, long double out_min)
{
    return ((x / x_max) * out_max) + (((x_max - x) / x_max) * out_min);
}

t_complex  sum_complex(t_complex z1, t_complex z2)
{
    t_complex result;

    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return (result);
}

t_complex   square_complex(t_complex z)
{
    t_complex result;

    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return (result);
}

