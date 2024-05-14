/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtoumi <wtoumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:58:25 by wtoumi            #+#    #+#             */
/*   Updated: 2024/05/14 04:44:30 by wtoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	handle_invalid_input(char **av, int index, int i)
{
	if (av[index][i] >= '0' && av[index][i] <= '9')
		return ;
	if (i != 0 && av[index][i] == '.')
		return ;
	write(1, "Invalid argument: non-digit found\n", 35);
	exit(EXIT_FAILURE);
}

void	check_multi_points(char *n)
{
	int	point_count;
	int	i;

	i = 0;
	point_count = 0;
	while (n[i])
	{
		if (n[i] == '.')
			point_count++;
		i++;
	}
	if (point_count > 1)
	{
		write(1, "Invalid argument: non-digit found\n", 35);
		exit(EXIT_FAILURE);
	}
}

void	check_julia(char **av, int index)
{
	int	i;

	i = 0;
	check_multi_points(av[index]);
	while (av[index][i] == ' ')
		i++;
	if (av[index][i] == '-' || av[index][i] == '+')
		i++;
	while (av[index][i])
	{
		handle_invalid_input(av, index, i);
		i++;
	}
}
