/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:45:10 by ealonso-          #+#    #+#             */
/*   Updated: 2022/04/20 16:11:14 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	countst(char **res)
{
	int	i;

	i = 0;
	while (res[i] != 0)
		i++;
	return (i);
}

void	*showing(t_sizes *s, char *image)
{
	void	*img;
	int		img_size;

	img = mlx_xpm_file_to_image(s->mlx_ptr, image,
			&img_size, &img_size);
	return (img);
}

void	remove_sprites(t_sizes *sizes)
{
	int	i;

	i = 0;
	while (sizes->spr[i])
	{
		mlx_destroy_image(sizes->mlx_ptr, sizes->spr[i]);
		i++;
	}
}
