/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:04:17 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/08 18:19:41 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_isdigit(const int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isspace(const int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

void	safe_exit_error(t_arena *arena)
{
	write(2, "Error\n", 6);
	arena_destroy(arena);
	exit(1);
}

long	ft_atoi(t_arena *arena, const char *str)
{
	long	sign;
	long	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (result * sign < INT_MIN || result * sign > INT_MAX)
		safe_exit_error(arena);
	return (result * sign);
}
