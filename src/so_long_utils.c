/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:45:10 by ealonso-          #+#    #+#             */
/*   Updated: 2022/04/12 16:03:36 by ealonso-         ###   ########.fr       */
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
