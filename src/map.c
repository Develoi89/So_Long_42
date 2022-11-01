/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: develoi89 <develoi89@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:50:57 by ealonso-          #+#    #+#             */
/*   Updated: 2022/11/01 08:43:07 by develoi89        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**reading_map(char *map)
{
	int		fd;
	char	*buff;
	char	**res;

	fd = open(map, O_RDONLY, 0);
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	read(fd, buff, BUFFER_SIZE);
	res = ft_split(buff, '\n');
	free (buff);
	close(fd);
	return (res);
}

int	readlen(char *map)
{
	int		fd;
	char	*buff;
	int		len;

	fd = open(map, O_RDONLY, 0);
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	len = read(fd, buff, BUFFER_SIZE);
	free(buff);
	close(fd);
	return (len);
}

void	comprove_ber(t_sizes *sizes)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (sizes->map[x] != 0)
	{
		y = 0;
		while (sizes->map[x][y] != '\0')
		{
			if (sizes->map[0][y] != '1'
			|| sizes->map[countst(sizes->map) - 1][y] != '1'
			|| sizes->map[x][0] != '1'
			|| sizes->map[x][ft_strlen(sizes->map[x]) - 1] != '1')
			{
				ft_printf("Error\ninvalid .ber file\n");
				exit (0);
			}
			y++;
		}
		x++;
	}
}

void	rect_map(t_sizes *sizes)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (sizes->map[x] != 0)
	{
		if (ft_strlen(sizes->map[x]) != ft_strlen(sizes->map[0]))
		{
			ft_printf("Error\nMap not rectangular\n");
			exit (0);
		}
		y = 0;
		while (sizes->map[x][y] != '\0')
		{
			y++;
		}
		x++;
	}	
}

void	elements_in_map(t_sizes *sizes)
{
	int	x;
	int	y;

	sizes->exit = 0;
	sizes->position = 0;
	sizes->coins = 0;
	x = -1;
	while (sizes->map[++x] != 0)
	{
		y = -1;
		while (sizes->map[x][++y] != '\0')
		{
			if (sizes->map[x][y] == 'E')
				sizes->exit++;
			else if (sizes->map[x][y] == 'P')
				sizes->position++;
			else if (sizes->map[x][y] == 'C')
				sizes->coins++;
		}
	}
	if (sizes->exit < 1 || sizes-> position < 1 || sizes->coins < 1)
	{
		ft_printf("Error\nNot enought elements\n");
		exit (0);
	}
}
