/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:09:09 by ealonso-          #+#    #+#             */
/*   Updated: 2022/04/13 18:41:23 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int can_we_move_it(int keycap, t_sizes *sizes)
{
	left = 0, 123
	up = 13, 126
	right = 2, 124
	down = 1, 125
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
		can_we_move_it(keycap, sizes);
	return (0);
}

