/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:42:47 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/11 19:36:02 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_strcmp(char *str_1, char *str_2)
{
	while (*str_1 == *str_2 && *str_1)
	{
		++str_1;
		++str_2;
	}
	return (*str_1 - *str_2);
}

static void	error(t_arena *a)
{
	arena_destroy(a);
	write(2, "Error\n", 6);
	exit(1);
}

static void	parse_command(t_data *data, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		pa(data);
	else if (!ft_strcmp(command, "pb\n"))
		pb(data);
	else if (!ft_strcmp(command, "sa\n"))
		sa(&(data->pile_a));
	else if (!ft_strcmp(command, "sb\n"))
		sb(&(data->pile_b));
	else if (!ft_strcmp(command, "ss\n"))
		ss(&(data->pile_a), &(data->pile_b));
	else if (!ft_strcmp(command, "ra\n"))
		ra(&(data->pile_a));
	else if (!ft_strcmp(command, "rb\n"))
		rb(&(data->pile_b));
	else if (!ft_strcmp(command, "rr\n"))
		rr(&(data->pile_a), &(data->pile_b));
	else if (!ft_strcmp(command, "rra\n"))
		rra(&(data->pile_a));
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(&(data->pile_b));
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(&(data->pile_a), &(data->pile_b));
	else
		error(data->arena);
}

int	main(int argc, char **argv)
{
	t_arena *arena;
	char *next_line;
	t_data *data;

	arena = arena_init(100000);
	if (1 == argc || check_args(argc))
	{
		arena_destroy(arena);
		return (0);
	}
	else if (2 == argc)
		argv = ft_split(arena, argv[1], 32);
	data = init_data(argc, arena);
	fill_data(data, argv, argc);
	next_line = get_next_line(STDIN_FILENO, arena);
	while (next_line)
	{
		parse_command(data, next_line);
		next_line = get_next_line(STDIN_FILENO, arena);
	}
	if (is_sorted(data->pile_a) && !data->pile_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(next_line);
	arena_destroy(arena);
}