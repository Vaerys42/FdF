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
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/includes/libft.h"

# define BLUE 0x000000FF
# define RED 0x00FF0000
# define GREEN 0x77b300
# define YELLOW 0x00FFFF00
# define PINK 0x0000FFFF
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define BROWN 0x662200typedef	struct 		s_one	t_one;

typedef struct 				s_key
{
	int				x;
	int				y;
}							t_key;

typedef struct 				s_data
{
	void			*mlx;
	void			*mlx_window;
	void			*mlx_image;
	char 			*image_string;
	int				s_l;
	int				bpp;
	int				endian;
}							t_data;

typedef	struct 				s_one
{
	int 			x;
	int 			y;
	int 			z;
	int				color;
	double			win_x;
	double			win_y;
	int				update;
	t_one			*next;
}							t_one;

typedef struct 				s_seg
{
	int				incr_x;
	int				incr_y;
	int				a_x;
	int				a_y;
	int				d_x;
	int				d_y;
}							t_seg;

typedef struct 				s_file
{
	t_one			*first_x;
	t_one			*current;
	t_one			*first_y;
}							t_file;

typedef struct 				s_fdf
{
	t_data			*data;
	t_file			*file;
	t_key			*key;
	t_seg			*seg;
	double			scale;
	double			space;
}							t_fdf;

void						open_new(t_fdf *fdf);
t_file						*ft_get_coord(char *path);

void						ft_error(void);
void						ft_error_file(void);

int							reader_len(char **reader);
t_file						*ft_return_len(t_file *file);
int							ft_line_len_x(t_file *file);
int							ft_line_len_y(t_file *file);

void						ft_create(t_fdf *fdf);
int							my_key_func(int key, t_fdf *fdf);
int							my_expose_hook(t_fdf *fdf);

char						**read_file(char *path);
void						ft_check_char(char **file);

t_file						*ft_add_list_x(t_file *file, int x, int y, int z);
t_file						*ft_add_list_y(t_file *file, int x, int y, int z);
t_file						*ft_new_list_x(int x, int y, int z, t_file *file);
t_file						*ft_new_list_y(int x, int y, int z, int len);

t_file						*ft_create_y(char **reader);
t_file						*ft_create_x(char **reader, t_file *file);
t_file						*ft_parse(char **reader);
t_file						*ft_get_coord(char *path);

double						smll(int x);

void						ft_draw_x(t_fdf *fdf);
void						ft_draw_y(t_fdf *fdf);
void						ft_co_win(t_fdf *fdf);

void						down_to_down(t_fdf *fdf);
void						down_to_zero(t_fdf *fdf);
void						zero_to_down(t_fdf *fdf);
void						down_to_up(t_fdf *fdf);
void						up_to_down(t_fdf *fdf);

void						ft_draw_seg(t_fdf *fdf);
void						dx_sup(t_fdf *fdf);
void						dy_sup(t_fdf *fdf);

double						x_iso(double x, double y, t_fdf *fdf);
double						y_iso_up(double x, double y, t_fdf *fdf);
double						y_iso(double x, double y, t_fdf *fdf);
double						y_iso_down(double x, double y, t_fdf *fdf);

int							get_color(int z);

void						more_alt(t_fdf *fdf);
void						less_alt(t_fdf *fdf);
#endif
