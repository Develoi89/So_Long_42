/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:59:58 by ealonso-          #+#    #+#             */
/*   Updated: 2022/04/06 17:25:39 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*wndw;

	mlx_ptr = mlx_init();
	wndw = mlx_new_window(mlx_ptr, 160, 80, "so_long");
	mlx_loop(mlx_ptr);
	return (0);
}
