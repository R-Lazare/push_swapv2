/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basefunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 05:17:02 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/09 20:37:59 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	update_attributes(t_pile **pile)
{
	t_pile	*temp;
	int		new_position;

	new_position = 0;
	(*pile)->first = *pile;
	temp = *pile;
	while (temp != NULL)
	{
		temp->position = new_position++;
		temp = temp->next;
	}
	temp = *pile;
	while (temp != NULL)
	{
		temp->size = new_position;
		temp = temp->next;
	}
	temp = *pile;
	while (temp->next != NULL)
		temp = temp->next;
	(*pile)->last = temp;
}

void	rotate(t_pile **pile)
{
	t_pile	*first;
	t_pile	*last;

	if (pile == NULL || *pile == NULL || (*pile)->next == NULL)
		return ;
	first = *pile;
	last = (*pile)->last;
	*pile = first->next;
	(*pile)->prev = NULL;
	if (last != first)
	{
		first->next = NULL;
		first->prev = last;
		last->next = first;
		(*pile)->last = first;
	}
}

void	ra(t_pile **pile_a)
{
	rotate(pile_a);
	update_attributes(pile_a);
	ft_printf("ra\n");
}

void	rb(t_pile **pile_b)
{
	rotate(pile_b);
	update_attributes(pile_b);
	ft_printf("rb\n");
}
