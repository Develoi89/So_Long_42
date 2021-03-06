/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:59:58 by ealonso-          #+#    #+#             */
/*   Updated: 2022/05/09 15:25:14 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	**save_spr(t_sizes *sizes)
{
	sizes->spr = calloc(sizeof(void *), (sizes->len));
	if (!sizes->spr)
		return (0);
	return (sizes->spr);
}

void	window(t_sizes *sizes)
{
	int		width;
	int		height;

	height = countst(sizes->map) * IMG_SIZE;
	width = ft_strlen(sizes->map[0]) * IMG_SIZE;
	sizes->mlx_ptr = mlx_init();
	sizes->wndw = mlx_new_window(sizes->mlx_ptr, (width), (height), "so_long");
}

void	*put_sprite(t_sizes *s, int x, int y)
{
	if (s->map[x][y] == '1')
		return (showing(s, "img/rock.xpm"));
	else if (s->map[x][y] == '0')
		return (showing(s, "img/floor.xpm"));
	else if (s->map[x][y] == 'C')
		return (showing(s, "img/collectable.xpm"));
	else if (s->map[x][y] == 'E')
		return (showing(s, "img/out.xpm"));
	else if (s->map[x][y] == 'P')
		return (showing(s, "img/hero.xpm"));
	else
		return (0);
}

void	mapping(t_sizes	*s)
{
	t_index	i;
	int		num;

	num = 0;
	i.x = 0;
	i.h = 0;
	while (s->map[i.x])
	{
		i.y = 0;
		i.w = 0;
		while (s->map[i.x][i.y] != '\n' && s->map[i.x][i.y])
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

	if (argc != 2 || ft_strrncmp(argv[1], ".ber", 4) != 0)
	{
		ft_printf("Error\nInvalid arguments");
		exit(0);
	}
	sizes.moves = 0;
	sizes.len = readlen(argv[1]) + 1;
	if (argc != 2)
		return (0);
	sizes.map = reading_map(argv[1]);
	comprove_ber(&sizes);
	rect_map(&sizes);
	elements_in_map(&sizes);
	sizes.spr = calloc(sizeof(void *), (sizes.len));
	if (!sizes.spr)
		return (0);
	window(&sizes);
	mapping(&sizes);
	sizes.coins = count_coins(&sizes);
	mlx_hook(sizes.wndw, 2, 0, move_it, &sizes);
	mlx_hook(sizes.wndw, 17, 0, close_it, &sizes);
	mlx_loop(sizes.mlx_ptr);
	return (0);
}
