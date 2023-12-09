/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:17:07 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/09 19:31:19 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_data	*init_data(int argc, t_arena *arena)
{
	t_data	*data;

	data = arena_alloc(arena, sizeof(t_data));
	data->pile_a = arena_alloc(arena, sizeof(t_pile));
	data->total_len = argc - 1;
	data->arena = arena;
	return (data);
}

void	safe_exit_error(t_arena *arena)
{
	printf("Error\n");
	arena_destroy(arena);
	exit(0);
}

int	check_format(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isalpha(str[i]))
			return (0);
		if (i != 0 && str[i] == '-')
			return (0);
		if (i == 0 && str[i] == '-' && str[i + 1] == '\0')
			return (0);
		if (str[i] != '-' && !ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	check_for_duplicates(t_arena *arena, t_pile *pile)
{
	t_pile	*current;
	t_pile	*next;

	current = pile;
	while (current->next != NULL)
	{
		next = current->next;
		while (next != NULL)
		{
			if (current->value == next->value)
				safe_exit_error(arena);
			next = next->next;
		}
		current = current->next;
	}
	return (0);
}

void	fill_array(t_data *data, char **int_tab_str)
{
	int		i;
	t_pile	*pile_a;

	i = 1;
	pile_a = data->pile_a;
	while (i <= data->total_len)
	{
		if (!check_format(int_tab_str[i - 1]))
			safe_exit_error(data->arena);
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
	check_for_duplicates(data->arena, data->pile_a);
}

void	fill_data(t_data *data, char **argv, int argc)
{
	char	**int_tab_str;
	t_pile	*pile_a;

	data->total_len = argc - 1;
	data->pile_a = (t_pile *)arena_alloc(data->arena, sizeof(t_pile));
	*(data->pile_a) = (t_pile){.cost = INT_MAX, .size = data->total_len,
		.next = NULL, .prev = NULL, .first = data->pile_a, .last = data->pile_a,
		.target = NULL, .position = 0, .value = 0};
	int_tab_str = &argv[1];
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
		printf("---------------------\n\n");
		pile = pile->next;
	}
}

void	print_piles(t_data *data)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = data->pile_a;
	pile_b = data->pile_b;
	while (pile_a != NULL || pile_b != NULL)
	{
		if (pile_a != NULL)
			printf("%d | ", pile_a->value);
		else
			printf("  | ");
		if (pile_b != NULL)
			printf("%d\n", pile_b->value);
		else
			printf("\n");
		if (pile_a != NULL)
			pile_a = pile_a->next;
		if (pile_b != NULL)
			pile_b = pile_b->next;
	}
	printf("\n");
}

int	check_args(int argc) //, char **argv)
{
	if (argc < 2)
		return (1);
	return (0);
}

static t_pile	*find_highest(t_pile *stack)
{
	int				highest;
	t_pile	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

static t_pile	*find_smallest(t_pile *stack)
{
	int				smallest;
	t_pile	*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = INT_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

void	sort_three(t_pile **pile_a)
{
	t_pile	*highest_node;

	highest_node = find_highest(*pile_a);
	if (*pile_a == highest_node)
		ra(pile_a);
	else if ((*pile_a)->next == highest_node)
		rra(pile_a);
	if ((*pile_a)->value > (*pile_a)->next->value)
		sa(pile_a);
}

int	is_sorted(t_pile *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	set_target_node(t_pile *a, t_pile *b)
{
	t_pile	*current_a;
	t_pile	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target = find_smallest(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	push_all_but_three(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->total_len - 3)
	{
		pb(data);
		i++;
	}
}

void	set_cost(t_pile *a, t_pile *b)
{
	int 	len_a;
	int 	len_b;

	len_a = a->size;
	len_b = b->size;
	while (b)
	{
		b->cost = b->position;
		if (b->position > len_b / 2)
			b->cost = len_b - b->position;
		if (b->target->position <= len_a / 2)
			b->cost += b->target->position;
		else
			b->cost += len_a - b->target->position;
		b = b->next;
	}
}

t_pile	*find_cheapest(t_pile *b)
{
	t_pile	*cheapest;

	cheapest = b;
	while (b)
	{
		if (b->cost < cheapest->cost)
			cheapest = b;
		b = b->next;
	}
	return (cheapest);
}

void	push_to_a(t_data *data)
{
	t_pile	*cheapest;

	cheapest = find_cheapest(data->pile_b);
	if (cheapest->position <= data->pile_b->size / 2 && cheapest->target->position <= data->pile_a->size / 2)
	{
		while (data->pile_b != cheapest && data->pile_a != cheapest->target)
			rr(&(data->pile_a), &(data->pile_b));
		while (data->pile_b != cheapest)
			rb(&(data->pile_b));
		while (data->pile_a != cheapest->target)
			ra(&(data->pile_a));
	}
	else if (cheapest->position > data->pile_b->size / 2 && cheapest->target->position > data->pile_a->size / 2)
	{
		while (data->pile_b != cheapest && data->pile_a != cheapest->target)
			rrr(&(data->pile_a), &(data->pile_b));
		while (data->pile_b != cheapest)
			rrb(&(data->pile_b));
		while (data->pile_a != cheapest->target)
			rra(&(data->pile_a));
	}
	else if (cheapest->position <= data->pile_b->size / 2 && cheapest->target->position > data->pile_a->size / 2)
	{
		while (data->pile_b != cheapest)
			rb(&(data->pile_b));
		while (data->pile_a != cheapest->target)
			rra(&(data->pile_a));
	}
	else if (cheapest->position > data->pile_b->size / 2 && cheapest->target->position <= data->pile_a->size / 2)
	{
		while (data->pile_b != cheapest)
			rrb(&(data->pile_b));
		while (data->pile_a != cheapest->target)
			ra(&(data->pile_a));
	}
	pa(data);
}

void	sort(t_pile **pile_a, t_pile **pile_b, t_data *data)
{
	t_pile	*lowest;
	
	push_all_but_three(data);
	sort_three(pile_a);
	while (*pile_b)
	{
		set_target_node(*pile_a, *pile_b);
		set_cost(*pile_a, *pile_b);
		push_to_a(data);
	}
	lowest = find_smallest(*pile_a);
	if (lowest->position <= data->total_len / 2)
		while (*pile_a != lowest)
			ra(pile_a);
	else
		while (*pile_a != lowest)
			rra(pile_a);
}

int	main(int argc, char **argv)
{
	t_arena	*arena;
	t_data	*data;

	arena = arena_init(100000);
	if (check_args(argc)) //, argv))
		return (0);
	data = init_data(argc, arena);
	fill_data(data, argv, argc);
	if (is_sorted(data->pile_a))
		return (0);
	if (data->total_len == 3)
		sort_three(&(data->pile_a));
	sort(&(data->pile_a), &(data->pile_b), data);
	arena_destroy(arena);
	return (0);
}
