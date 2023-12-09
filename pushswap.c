/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:17:07 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/09 20:53:09 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	safe_exit_error(t_arena *arena)
{
	ft_printf("Error\n");
	arena_destroy(arena);
	exit(0);
}

int	check_args(int argc)
{
	if (argc < 2)
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

int	main(int argc, char **argv)
{
	t_arena	*arena;
	t_data	*data;

	arena = arena_init(100000);
	if (check_args(argc))
		return (0);
	data = init_data(argc, arena);
	fill_data(data, argv, argc);
	if (is_sorted(data->pile_a))
		return (0);
	if (data->total_len == 3)
		sort_three(&(data->pile_a));
	if (is_sorted(data->pile_a))
		return (0);
	sort(&(data->pile_a), &(data->pile_b), data);
	arena_destroy(arena);
	return (0);
}
