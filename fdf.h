/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:35:21 by kboucaud          #+#    #+#             */
/*   Updated: 2017/03/08 18:55:07 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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

typedef struct		s_data
{
	void		*mlx;
	void		*mlx_window;
}					t_data;

typedef	struct 		s_coo
{
	int			x;
	int			y;
}					t_coo;

char		**ft_get_file(char *path);
int			open_new(int coo[5][6]);
int			**ft_coo_tab(char **tab, int length, int height);
void		ft_draw_seg(int xa, int xb, int ya, int yb, t_data data);
void		ft_draw_x(int coo[5][6], t_data data);
int 		y_iso(int y, int x);
int 		x_iso(int x, int y);
void		ft_draw_y(int coo[5][6], t_data data);
void		dx_sup(t_data data, t_coo d, t_coo incr, t_coo a);
void		dy_sup(t_data data, t_coo d, t_coo incr, t_coo a);

#endif
