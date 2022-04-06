/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:59:58 by ealonso-          #+#    #+#             */
/*   Updated: 2022/04/06 18:53:11 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_sizes	sizes;

	sizes.mlx_ptr = mlx_init();
	sizes.wndw = mlx_new_window(sizes.mlx_ptr, 160, 80, "so_long");
	mlx_loop(sizes.mlx_ptr);
	return (0);
}
