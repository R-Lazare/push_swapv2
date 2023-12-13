/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:50:20 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/11 19:58:45 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static char	*allocate_and_copy(const char *src, const char *buff,
		t_arena *arena)
{
	char	*dest;
	int		length;
	int 	i;

	length = ft_strlen_line(buff) + 1;
	if (src)
	{
		length += ft_strlen(src);
	}
	dest = arena_alloc(arena, sizeof(char) * length + 1);
	if (!dest)
	{
		return (NULL);
	}
	i = 0;
	if (src)
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}

static char	*concatenate_line(char *dest, const char *buff)
{
	int	i;
	int	j;

	if (dest)
		i = ft_strlen(dest);
	else
		i = 0;
	j = 0;
	while (buff[j] && buff[j] != '\n')
	{
		dest[i++] = buff[j++];
	}
	dest[i++] = '\n';
	dest[i] = '\0';
	if (dest[0] == '\0')
	{
		return (NULL);
	}
	return (dest);
}

char	*ft_join_line(char *src, char *buff, t_arena *arena)
{
	char	*dest;

	dest = allocate_and_copy(src, buff, arena);
	if (!dest)
	{
		return (NULL);
	}
	return (concatenate_line(dest, buff));
}
