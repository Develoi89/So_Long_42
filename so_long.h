/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:16:15 by ealonso-          #+#    #+#             */
/*   Updated: 2022/05/09 15:27:31 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# define BUFFER_SIZE 4096
# define IMG_SIZE 32

typedef struct s_sizes
{
	void	*mlx_ptr;
	void	*wndw;
	void	**spr;
	char	**map;
	int		hx;
	int		hy;
	int		moves;
	int		len;
	int		coins;
	int		exit;
	int		position;
}	t_sizes;

typedef struct s_index
{
	int		x;
	int		y;
	int		h;
	int		w;
}	t_index;

char	**reading_map(char *map);
int		countst(char **res);
void	*showing(t_sizes *s, char *image);
int		readlen(char *map);
int		close_it(void);
int		move_it(int keycap, t_sizes *sizes);
int		lets_move(int keycap, t_sizes *sizes);
void	mapping(t_sizes	*s);
void	*put_sprite(t_sizes *s, int x, int y);
void	remove_sprites(t_sizes *sizes);
void	window(t_sizes *sizes);
void	**save_spr(t_sizes *sizes);
void	found_the_hero(t_sizes *sizes);
int		count_coins(t_sizes *sizes);
void	comprove_ber(t_sizes *sizes);
void	rect_map(t_sizes *sizes);
void	elements_in_map(t_sizes *sizes);

#endif
