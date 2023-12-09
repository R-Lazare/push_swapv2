/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:17:05 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/09 20:21:18 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_arena
{
	void			*buf;
	size_t			buf_size;
	size_t			prev_offset;
	size_t			curr_offset;
}					t_arena;

void				*arena_init(size_t buffer_size);
void				arena_reset(t_arena *a);
void				*arena_alloc(t_arena *a, size_t size);
void				arena_destroy(t_arena *a);

typedef struct s_pile
{
	struct s_pile	*next;
	struct s_pile	*prev;
	struct s_pile	*first;
	struct s_pile	*last;
	struct s_pile	*target;
	int				position;
	int				size;
	int				cost;
	int				value;
}					t_pile;

typedef struct s_data
{
	t_pile			*pile_a;
	t_pile			*pile_b;
	int				total_len;
	t_arena			*arena;
}					t_data;

char				**ft_split(t_arena *arena, char const *s, char c);
int					count_words(char const *s, char c);
long				ft_atoi(t_arena *arena, const char *str);
char				*ft_substr(t_arena *arena, char const *s,
						unsigned int start, size_t len);
void				ra(t_pile **pile_a);
void				rb(t_pile **pile_b);
void				rra(t_pile **pile_a);
void				rrb(t_pile **pile_b);
void				sa(t_pile **pile_a);
void				print_structure(t_pile *pile);
void				pa(t_data *data);
void				pb(t_data *data);
void				rrr(t_pile **pile_a, t_pile **pile_b);
void				rr(t_pile **pile_a, t_pile **pile_b);
void				rrotate(t_pile **pile);
int					ft_isalpha(const int c);
void				safe_exit_error(t_arena *arena);
int					ft_isdigit(const int c);
int					ft_printf(const char *src, ...);