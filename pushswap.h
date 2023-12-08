/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:17:05 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/08 18:19:59 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <limits.h>
#include <math.h>
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
	int				*total_len;
	t_arena			*arena;
}					t_data;

char				**ft_split(t_arena *arena, char const *s, char c);
int					count_words(char const *s, char c);
long				ft_atoi(t_arena *arena, const char *str);
