/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:16:15 by ealonso-          #+#    #+#             */
/*   Updated: 2022/04/13 17:47:56 by ealonso-         ###   ########.fr       */
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
int		move_it(int keycap);

#endif