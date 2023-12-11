/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basefunc4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:38:18 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/11 19:09:56 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_data *data)
{
	t_pile	*top_b;

	if (data->pile_b == NULL)
		return ;
	top_b = data->pile_b;
	data->pile_b = top_b->next;
	if (data->pile_b != NULL)
		data->pile_b->prev = NULL;
	if (data->pile_a != NULL)
		data->pile_a->prev = top_b;
	top_b->next = data->pile_a;
	top_b->prev = NULL;
	data->pile_a = top_b;
	if (data->pile_a->next == NULL)
		data->pile_a->last = data->pile_a;
	update_attributes(&data->pile_a);
	if (data->pile_b != NULL)
		update_attributes(&data->pile_b);
	ft_printf("pa\n");
}

void	pb(t_data *data)
{
	t_pile	*top_a;

	if (data->pile_a == NULL)
		return ;
	top_a = data->pile_a;
	data->pile_a = top_a->next;
	if (data->pile_a != NULL)
		data->pile_a->prev = NULL;
	if (data->pile_b != NULL)
		data->pile_b->prev = top_a;
	top_a->next = data->pile_b;
	top_a->prev = NULL;
	data->pile_b = top_a;
	if (data->pile_b->next == NULL)
		data->pile_b->last = data->pile_b;
	update_attributes(&data->pile_b);
	if (data->pile_a != NULL)
		update_attributes(&data->pile_a);
	ft_printf("pb\n");
}
