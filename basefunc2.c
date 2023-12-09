/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basefunc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:36:48 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/09 20:37:44 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	ft_printf("sa\n");
}

void	sb(t_pile **pile_b)
{
	swap(pile_b);
	ft_printf("sb\n");
}

void	ss(t_pile **pile_a, t_pile **pile_b)
{
	swap(pile_a);
	swap(pile_b);
	ft_printf("ss\n");
}
