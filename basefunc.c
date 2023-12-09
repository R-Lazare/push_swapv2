/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basefunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 05:17:02 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/09 15:44:28 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_pile **pile)
{
	t_pile	*first;
	t_pile	*last;

	if (pile == NULL || *pile == NULL || (*pile)->next == NULL)
		return ;
	first = (*pile)->first;
	last = (*pile)->last;
	*pile = first->next;
	(*pile)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	while (last->next != NULL)
		last = last->next;
	(*pile)->last = last;
}

void	ra(t_pile **pile_a)
{
	rotate(pile_a);
	printf("ra\n");
}

void	rb(t_pile **pile_b)
{
	rotate(pile_b);
	printf("rb\n");
}

void	rrotate(t_pile **pile)
{
	t_pile	*first;
	t_pile	*last;

	if (pile == NULL || *pile == NULL || (*pile)->next == NULL)
		return ;
	first = (*pile)->first;
	last = (*pile)->last;
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	*pile = last;
	while (last->next != NULL)
		last = last->next;
	(*pile)->last = last;
}

void	rra(t_pile **pile_a)
{
	rrotate(pile_a);
	printf("rra\n");
}

void	rrb(t_pile **pile_b)
{
	rrotate(pile_b);
	printf("rrb\n");
}

void	swap(t_pile **pile)
{
	t_pile	*first;

	if (pile == NULL || *pile == NULL)
		return ;
	*pile = (*pile)->next;
	(*pile)->prev->prev = *pile;
	(*pile)->prev->next = (*pile)->next;
	if ((*pile)->next)
		(*pile)->next->prev = (*pile)->prev;
	(*pile)->next = (*pile)->prev;
	(*pile)->prev = NULL;
	first = (*pile)->first;
	while (first->prev != NULL)
		first = first->prev;
	(*pile)->first = first;
}

void	sa(t_pile **pile_a)
{
	swap(pile_a);
	printf("sa\n");
}

void	sb(t_pile **pile_b)
{
	swap(pile_b);
	printf("sb\n");
}

void	ss(t_pile **pile_a, t_pile **pile_b)
{
	swap(pile_a);
	swap(pile_b);
	printf("ss\n");
}

void	update_attributes(t_pile **pile)
{
	t_pile	*temp;
	int		new_position;

	new_position = 1;
	temp = *pile;
	while (temp != NULL)
	{
		temp->position = new_position++;
		temp = temp->next;
	}
	temp = *pile;
	while (temp != NULL)
	{
		temp->size = new_position - 1;
		temp = temp->next;
	}
}

void	pa(t_data *data)
{
	t_pile	*top_b;

	// Check if there is anything to push from pile_b to pile_a
	if (data->pile_b == NULL)
		return ;
	top_b = data->pile_b;
	data->pile_b = top_b->next; // Move the head of pile_b down
	if (data->pile_b != NULL)
		data->pile_b->prev = NULL;
	if (data->pile_a != NULL)
		data->pile_a->prev = top_b;
			// Set the current top of pile_a to be below new top
	top_b->next = data->pile_a;
		// Place the previous top of pile_b above the current top of pile_a
	top_b->prev = NULL;         // Now top_b is the first element so no previous
	data->pile_a = top_b;       // Update the head of pile_a
	if (data->pile_a->next == NULL)        // If there's only one element
		data->pile_a->last = data->pile_a; // Update last pointer
	update_attributes(&data->pile_a);
	update_attributes(&data->pile_b);
	printf("pa\n");
}

void	pb(t_data *data)
{
	t_pile	*top_a;

	// Check if there is anything to push from pile_a to pile_b
	if (data->pile_a == NULL)
		return ;
	top_a = data->pile_a;
	data->pile_a = top_a->next; // Move the head of pile_a down
	if (data->pile_a != NULL)
		data->pile_a->prev = NULL;
	if (data->pile_b != NULL)
		data->pile_b->prev = top_a;
			// Set the current top of pile_b to be below new top
	top_a->next = data->pile_b;
		// Place the previous top of pile_a above the current top of pile_b
	top_a->prev = NULL;         // Now top_a is the first element so no previous
	data->pile_b = top_a;       // Update the head of pile_b
	if (data->pile_b->next == NULL)        // If there's only one element
		data->pile_b->last = data->pile_b; // Update last pointer
	update_attributes(&data->pile_b);
	update_attributes(&data->pile_a);
	printf("pb\n");
}
