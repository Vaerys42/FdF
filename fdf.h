/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:35:21 by kboucaud          #+#    #+#             */
/*   Updated: 2017/05/04 15:00:20 by kboucaud         ###   ########.fr       */
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
# include "minilibx_macos/mlx.h"
# include "libft/includes/libft.h"

# define BLUE 0x000000FF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define YELLOW 0x00FFFF00
# define PINK 0x0000FFFF
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000

typedef	struct 		s_one	t_one;

typedef struct		s_data
{
	void		*mlx;
	void		*mlx_window;
}					t_data;

typedef struct 		s_seg
{
	double			xa;
	double			xb;
	double			ya;
	double			yb;
	t_data			data;
}					t_seg;

typedef	struct 		s_one
{
	int 			x;
	int 			y;
	int 			z;
	t_one			*next;
}					t_one;

typedef struct 		s_file
{
	t_one			*first;
	t_one			*current;
	t_data			data;
}					t_file;


typedef	struct		s_coo
{
	double			x;
	double			y;
	t_data			data;
}					t_coo;
	
void				open_new(t_file *coo);
t_file				*ft_get_coord(char *path);
void				ft_error(void);

char				**read_file(char *path);
void				ft_check_char(char **file);
t_file				*ft_add_list(t_file *file, int x, int y, int z);
t_file				*ft_new_list(int x, int y, int z);
t_file				*ft_parse(char **reader);
t_file				*ft_get_coord(char *path);

void				ft_draw_seg(t_seg send);
void				dx_sup(t_data data, t_coo d, t_coo incr, t_coo a);
void				dy_sup(t_data data, t_coo d, t_coo incr, t_coo a);
double				smll(int x);

t_seg				ft_line_x_under_1(t_coo co, int val1, int val2);
t_seg				ft_line_x_under_2(t_coo co, int val1, int val2);
void				ft_line_x(t_coo co, int val1, int val2);
t_seg				ft_line_y_under_1(t_coo co, int val1, int val2);
t_seg				ft_line_y_under_2(t_coo co, int val1, int val2);
void				ft_line_y(t_coo co, int val1, int val2);
void				ft_draw_x(t_file *file);
void				ft_draw_y(t_file *file);

double				x_iso(double x, double y);
double				y_iso_up(double x, double y);
double				y_iso(double x, double y);

#endif
