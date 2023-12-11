/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:17:07 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/11 19:45:48 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	safe_exit_error(t_arena *arena)
{
	ft_printf("Error\n");
	arena_destroy(arena);
	exit(0);
}

void	safe_exit(t_arena *arena)
{
	arena_destroy(arena);
	exit(0);
}

int	check_args(int argc)
{
	if (argc <= 2)
		return (1);
	return (0);
}

void	push_all_but_three(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_len - 3)
	{
		pb(data);
		i++;
	}
}
