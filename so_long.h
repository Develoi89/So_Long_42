/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:16:15 by ealonso-          #+#    #+#             */
/*   Updated: 2022/04/12 15:38:23 by ealonso-         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef IMG_SIZE
#  define IMG_SIZE 32
# endif

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

#endif