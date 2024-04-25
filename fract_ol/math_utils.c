/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:19:25 by wtoumi            #+#    #+#             */
/*   Updated: 2024/04/25 16:37:36 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double map(long x, long in_min, long in_max, long out_min, long out_max)
{
    return (x - in_min) * (out_max - out_min) / ((in_max - in_min) + out_min);
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
