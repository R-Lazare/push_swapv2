/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:40:23 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/09 20:40:30 by rluiz            ###   ########.fr       */
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
