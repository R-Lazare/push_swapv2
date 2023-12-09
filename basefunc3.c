/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basefunc3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:37:33 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/09 20:37:41 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rrotate(t_pile **pile)
{
	int	i;

	i = 0;
	while (i < (*pile)->size - 1)
	{
		rotate(pile);
		i++;
	}
}

void	rra(t_pile **pile_a)
{
	rrotate(pile_a);
	update_attributes(pile_a);
	ft_printf("rra\n");
}

void	rrb(t_pile **pile_b)
{
	rrotate(pile_b);
	update_attributes(pile_b);
	ft_printf("rrb\n");
}

void	rrr(t_pile **pile_a, t_pile **pile_b)
{
	rrotate(pile_a);
	rrotate(pile_b);
	ft_printf("rrr\n");
}

void	rr(t_pile **pile_a, t_pile **pile_b)
{
	rotate(pile_a);
	rotate(pile_b);
	ft_printf("rr\n");
}
