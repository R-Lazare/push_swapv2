/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:41:39 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/09 20:53:01 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_pile	*find_highest(t_pile *stack)
{
	int		highest;
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

t_pile	*find_smallest(t_pile *stack)
{
	int		smallest;
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

void	set_target_node(t_pile *a, t_pile *b)
{
	t_pile	*current_a;
	t_pile	*target_node;
	long	best_match_index;

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
