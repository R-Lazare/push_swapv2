/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basefunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 05:17:02 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/09 06:12:23 by rluiz            ###   ########.fr       */
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

void    ra(t_pile **pile_a)
{
    rotate(pile_a);
    printf("ra\n");
}

void    rb(t_pile **pile_b)
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

