/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:17:07 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/08 18:20:19 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_data	*init_data(int argc, t_arena *arena)
{
	t_data	*data;

	data = arena_alloc(arena, sizeof(t_data));
	data->pile_a = arena_alloc(arena, sizeof(t_pile));
	data->pile_b = arena_alloc(arena, sizeof(t_pile));
	data->total_len = argc - 1;
	data->arena = arena;
	return (data);
}

void	fill_array(t_data *data, char **int_tab_str)
{
	int		i;
	t_pile	*pile_a;

	i = 1;
	pile_a = data->pile_a;
	while (i <= data->total_len)
	{
		pile_a->value = ft_atoi(data->arena, int_tab_str[i - 1]);
		pile_a->position = i;
		pile_a->size = data->total_len;
		pile_a->cost = INT_MAX;
		pile_a->target = NULL;
		pile_a->next = (t_pile *)arena_alloc(data->arena, sizeof(t_pile));
		pile_a->next->prev = pile_a;
		pile_a->next->first = pile_a->first;
		pile_a = pile_a->next;
		i++;
	}
	pile_a->prev->next = NULL;
	data->arena->curr_offset = data->arena->prev_offset;
}

void	fill_data(t_data *data, char **argv)
{
	char	**int_tab_str;
	t_pile	*pile_a;

	data->total_len = count_words(argv[1], ' ');
	data->pile_a = (t_pile *)arena_alloc(data->arena, sizeof(t_pile));
	*(data->pile_a) = (t_pile){.cost = INT_MAX, .size = data->total_len,
		.next = NULL, .prev = NULL, .first = data->pile_a, .last = data->pile_a,
		.target = NULL, .position = 0, .value = 0};
	*(data->pile_b) = (t_pile){.cost = INT_MAX, .size = 0, .next = NULL,
		.prev = NULL, .first = NULL, .last = NULL, .target = NULL,
		.position = 0, .value = 0};
	int_tab_str = ft_split(data->arena, argv[1], ' ');
	fill_array(data, int_tab_str);
	pile_a = data->pile_a;
	while (pile_a->next != NULL)
		pile_a = pile_a->next;
	pile_a->last = pile_a;
	while (pile_a->prev != NULL)
	{
		pile_a->prev->last = pile_a->last;
		pile_a = pile_a->prev;
	}
}

void	print_structure(t_pile *pile)
{
	while (pile != NULL)
	{
		printf("address: %p\n", (void *)pile);
		printf("Value: %d\n", pile->value);
		printf("Position: %d\n", pile->position);
		printf("Size: %d\n", pile->size);
		printf("Cost: %d\n", pile->cost);
		printf("Target: %p\n", (void *)pile->target);
		printf("Next: %p\n", (void *)pile->next);
		printf("Prev: %p\n", (void *)pile->prev);
		printf("First: %p\n", (void *)pile->first);
		printf("Last: %p\n", (void *)pile->last);
		printf("---------------------\n");
		pile = pile->next;
	}
}

int	check_args(int argc) //, char **argv)
{
	if (argc < 2)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_arena	*arena;
	t_data	*data;

	arena = arena_init(2048);
	if (check_args(argc)) //, argv))
		return (0);
	data = init_data(argc, arena);
	// argument is a single string containing all the numbers like "1 2 -3 4 -5"
	fill_data(data, argv);
	print_structure(data->pile_a);
	return (0);
}
