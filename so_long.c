/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:59:58 by ealonso-          #+#    #+#             */
/*   Updated: 2022/04/05 16:40:41 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*wndw;

	mlx_ptr = mlx_init();
	wndw = mlx_new_window(mlx_ptr, 20, 40, "so_long");
	mlx_loop(mlx_ptr);
	return (0);
}
