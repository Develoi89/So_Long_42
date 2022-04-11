/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:59:58 by ealonso-          #+#    #+#             */
/*   Updated: 2022/04/11 18:14:15 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*put_sprite(t_sizes *s, int x, int y)
{
	if (s->map[x][y] == '1')
		return (showing(s, "./img/rock.xpm"));
	if (s->map[x][y] == '0')
		return (showing(s, "./img/floor.xpm"));
	if (s->map[x][y] == 'C')
		return (showing(s, "./img/collectable.xpm"));
	if (s->map[x][y] == 'E')
		return (showing(s, "./img/out.xpm"));
	if (s->map[x][y] == 'P')
		return (showing(s, "./img/hero.xpm"));
	return (0);
}

void	mapping(t_sizes	*s)
{
	t_index	i;
	int		num;

	num = 0;
	i.x = 0;
	i.h = 0;
	while (s->map[i.x] != 0)
	{
		i.y = 0;
		i.w = 0;
		while (s->map[i.x][i.y] != '\n' && s->map[i.x][i.y] != '\0')
		{
			s->spr[num] = put_sprite(s, i.x, i.y);
			if (s->spr[num] == NULL)
				exit(0);
			mlx_put_image_to_window(s->mlx_ptr, s->wndw,
				s->spr[num++], i.w, i.h);
			i.w += IMG_SIZE;
			i.y++;
		}
		i.h += IMG_SIZE;
		i.x++;
	}
}

int	main(int argc, char **argv)
{
	t_sizes	sizes;
	int		width;
	int		height;

	if (argc != 2)
		return (0);
	sizes.map = reading_map(argv[1]);
	height = countst(sizes.map) * IMG_SIZE;
	width = ft_strlen(sizes.map[0] - 1) * IMG_SIZE;
	sizes.mlx_ptr = mlx_init();
	sizes.wndw = mlx_new_window(sizes.mlx_ptr, (width), (height), "so_long");
	mapping(&sizes);
	mlx_loop(sizes.mlx_ptr);
	return (0);
}
