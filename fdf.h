/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:35:21 by kboucaud          #+#    #+#             */
/*   Updated: 2017/03/03 14:35:22 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_F
# define FDF_F

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "minilibx/mlx.h"
# include "libft/includes/libft.h"

# define BLUE 0x000000FF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define YELLOW 0x00FFFF00
# define PINK 0x0000FFFF
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000

typedef struct 		s_coord
{
	int				x;
	int				y;
	int				z;
	struct s_coord	*next;
}					t_coord;

typedef struct 	s_data
{
	void		*mlx;
	void		*mlx_window;
}				t_data;

char		**ft_get_file(char *path);
int			open_new();

#endif