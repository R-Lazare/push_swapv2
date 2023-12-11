/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:57:34 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/11 18:57:38 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
