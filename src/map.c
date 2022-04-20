/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:50:57 by ealonso-          #+#    #+#             */
/*   Updated: 2022/04/20 15:30:53 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
