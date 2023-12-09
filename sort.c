/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:43:38 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/09 20:52:49 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_cost(t_pile *a, t_pile *b)
{
	int	len_a;
	int	len_b;

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

void	push_a_helper(t_data *data, t_pile *cheapest)
{
	if (cheapest->position > data->pile_b->size / 2
		&& cheapest->target->position > data->pile_a->size / 2)
	{
		while (data->pile_b != cheapest && data->pile_a != cheapest->target)
			rrr(&(data->pile_a), &(data->pile_b));
		while (data->pile_b != cheapest)
			rrb(&(data->pile_b));
		while (data->pile_a != cheapest->target)
			rra(&(data->pile_a));
	}
	else if (cheapest->position <= data->pile_b->size / 2
		&& cheapest->target->position > data->pile_a->size / 2)
	{
		while (data->pile_b != cheapest)
			rb(&(data->pile_b));
		while (data->pile_a != cheapest->target)
			rra(&(data->pile_a));
	}
	else
	{
		while (data->pile_b != cheapest)
			rrb(&(data->pile_b));
		while (data->pile_a != cheapest->target)
			ra(&(data->pile_a));
	}
}

void	push_to_a(t_data *data)
{
	t_pile	*cheapest;

	cheapest = find_cheapest(data->pile_b);
	if (cheapest->position <= data->pile_b->size / 2
		&& cheapest->target->position <= data->pile_a->size / 2)
	{
		while (data->pile_b != cheapest && data->pile_a != cheapest->target)
			rr(&(data->pile_a), &(data->pile_b));
		while (data->pile_b != cheapest)
			rb(&(data->pile_b));
		while (data->pile_a != cheapest->target)
			ra(&(data->pile_a));
	}
	else
		push_a_helper(data, cheapest);
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
