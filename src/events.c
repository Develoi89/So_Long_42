/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:09:09 by ealonso-          #+#    #+#             */
/*   Updated: 2022/04/25 15:51:06 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*lets_swap(int x, int y, t_sizes *sizes)
{
	remove_sprites(sizes);
	mlx_clear_window(sizes->mlx_ptr, sizes->wndw);
	if (sizes->map[sizes->hx + x][sizes->hy + y] == 'C')
		sizes->coins--;
	if (sizes->map[sizes->hx + x][sizes->hy + y] == 'E'
		&& sizes->coins == 0)
		close_it();
	if (sizes->map[sizes->hx + x][sizes->hy + y] == 'E'
		&& sizes->coins > 0)
	{
		mapping(sizes);
		return (0);
	}
	sizes->map[sizes->hx + x][sizes->hy + y] = 'P';
	sizes->map[sizes->hx][sizes->hy] = '0';
	sizes->spr = save_spr(sizes);
	sizes->moves++;
	printf("moves:%d\n", sizes->moves);
	mapping(sizes);
	return (0);
}

void	found_the_hero(t_sizes *sizes)
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
			if (sizes->map[x][y] == 'P')
				break ;
			y++;
		}
		if (sizes->map[x][y] == 'P')
			break ;
		x++;
	}
	sizes->hx = x;
	sizes->hy = y;
}

int	lets_move(int keycap, t_sizes *sizes)
{
	found_the_hero(sizes);
	if ((keycap == 0 || keycap == 123)
		&& sizes->map[sizes->hx][sizes->hy - 1] != '1')
		lets_swap(0, -1, sizes);
	if ((keycap == 13 || keycap == 126)
		&& sizes->map[sizes->hx - 1][sizes->hy] != '1')
		lets_swap(-1, 0, sizes);
	if ((keycap == 2 || keycap == 124)
		&& sizes->map[sizes->hx][sizes->hy + 1] != '1')
		lets_swap(0, +1, sizes);
	if ((keycap == 1 || keycap == 125)
		&& sizes->map[sizes->hx + 1][sizes->hy] != '1')
		lets_swap(+1, 0, sizes);
	else
		return (0);
	return (0);
}

int	close_it(void)
{
	exit(0);
}

int	move_it(int keycap, t_sizes *sizes)
{
	if (keycap == 53)
		close_it();
	else
		lets_move(keycap, sizes);
	return (0);
}
