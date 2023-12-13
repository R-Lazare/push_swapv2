/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:49:46 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/11 19:58:26 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

#define BUFFER_SIZE 4

int	ft_check_line(char *dest)
{
	int	i;

	i = 0;
	if (!dest)
		return (0);
	while (dest[i] && dest[i] != '\n')
		i++;
	if (dest[i] == '\n')
		return (1);
	return (0);
}

int	ft_strlen_line(const char *dest)
{
	int	i;

	i = 0;
	if (!dest)
		return (0);
	while (dest[i] && dest[i] != '\n')
		i++;
	return (i);
}

// char	*ft_join_line(char *src, char *buff, t_arena *arena)
// {
// 	int		i;
// 	int		j;
// 	char	*dest;

// 	i = 0;
// 	j = 0;
// 	if (!src)
// 		dest = arena_alloc(arena, sizeof(char) * ft_strlen_line(buff) + 2);
// 	else
// 	{
// 		dest = arena_alloc(arena, sizeof(char) * ft_strlen_line(buff)
// 			+ ft_strlen(src) + 2);
// 		while (src[i])
// 		{
// 			dest[i] = src[i];
// 			i++;
// 		}
// 	}
// 	while (buff[j] && buff[j] != '\n')
// 	{
// 		dest[i] = buff[j];
// 		i++;
// 		j++;
// 	}
// 	dest[i] = '\n';
// 	if (buff[j] == '\n')
// 		i++;
// 	dest[i] = '\0';
// 	if (dest[0] == '\0')
// 		return (NULL);
// 	return (dest);
// }

void	ft_cut_line(char *dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] && dest[i] != '\n')
		i++;
	if (dest[i] == '\n')
		i++;
	while (dest[i])
		dest[j++] = dest[i++];
	while (j < BUFFER_SIZE)  // Clear out the remaining buffer content
		dest[j++] = '\0';
}

char	*get_next_line(int fd, t_arena *arena)
{
	static char	buff[BUFFER_SIZE + 1];
	int			i;
	char		*dest;

	i = 1;
	dest = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (ft_check_line(buff) == 1)
	{
		ft_cut_line(buff); // Rename function to `ft_cut_line`
		dest = ft_join_line(dest, buff, arena);
	}
	while (i > 0 && ft_check_line(buff) == 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0)
			return (dest);
		buff[i] = '\0';
		dest = ft_join_line(dest, buff, arena);
	}
	return (dest);
}
