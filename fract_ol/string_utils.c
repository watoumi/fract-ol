/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:58:25 by wtoumi            #+#    #+#             */
/*   Updated: 2024/04/27 21:11:06 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1)
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}

void	putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	if (*s)
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

double	atodbl(char *s)
{
	long	i;
	long	j;
	double	pow;
	int		sign;

	i = 0;
	j = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
	{
		if ('-' == *s++)
			sign = -sign;
	}
	while (*s != '.' && *s)
		i = (i * 10) + (*s++ - 48);
	if ('.' == *s)
		s++;
	while (*s)
	{
		pow /= 10;
		j = j + (*s++ - 48) * pow;
	}
	return ((i + j) * sign);
}
