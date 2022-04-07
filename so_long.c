/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:59:58 by ealonso-          #+#    #+#             */
/*   Updated: 2022/04/07 18:20:10 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapping(t_sizes	*sizes)
{
	t_index	index;
	
}

int	main(int argc, char **argv)
{
	t_sizes	sizes;
	int		width;
	int		height;

	if (argc != 2)
		return (0);
	sizes.map = reading_map(argv[1]);
	height = (ft_strlen((char *)sizes.map) + 1) * 32;
	width = ft_strlen(sizes.map[0]) * 32;
	sizes.mlx_ptr = mlx_init();
	sizes.wndw = mlx_new_window(sizes.mlx_ptr, (width), (height), "so_long");
	mapping(&sizes);
	mlx_loop(sizes.mlx_ptr);
	return (0);
}
