/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:59:58 by ealonso-          #+#    #+#             */
/*   Updated: 2022/04/06 20:04:06 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_sizes	sizes;
	int		width;
	int		height;

	if (argc != 2)
		return (0);
	sizes.map = ft_split(argv[1], '\n');
	height = ft_strlen(*sizes.map);
	width = ft_strlen(sizes.map[0]);
	sizes.mlx_ptr = mlx_init();
	sizes.wndw = mlx_new_window(sizes.mlx_ptr, (width), (height), "so_long");
	mlx_loop(sizes.mlx_ptr);
	return (0);
}
