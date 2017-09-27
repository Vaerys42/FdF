/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:35:08 by kboucaud          #+#    #+#             */
/*   Updated: 2017/03/03 14:35:09 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_create(t_fdf *fdf)
{
	if ((fdf->data = (t_data*)malloc(sizeof(t_data))) == NULL)
		ft_error();
	if ((fdf->data->mlx = mlx_init()) == NULL)
		ft_error();
	if ((fdf->data->mlx_window = mlx_new_window(fdf->data->mlx, 1000, 800, "Fdf")) == NULL)
		ft_error();
	if ((fdf->data->mlx_image = mlx_new_image(fdf->data->mlx, 1000, 800)) == NULL)
		ft_error();
	if ((fdf->data->image_string = mlx_get_data_addr(fdf->data->mlx_image, &(fdf->data->bpp), &(fdf->data->s_l), &(fdf->data->endian))) == NULL)
		ft_error();
	if ((fdf->key = (t_key*)malloc(sizeof(t_key))) == NULL)
		ft_error();
	if ((fdf->seg = (t_seg*)malloc(sizeof(t_seg))) == NULL)
		ft_error();
	fdf->key->x = 0;
	fdf->key->y = 0;
}

int			my_key_func(int key, t_fdf *fdf)
{
	int 	i;

	i = 10;
	if (key == 53)
		exit(1);
	if (key == 124)
		fdf->key->x += i;
	if (key == 123 && fdf->key->x > 0)
		fdf->key->x -= i;
	if (key == 125)
		fdf->key->y += i;
	if (key == 126 && fdf->key->y > 0)
		fdf->key->y -= i;
	open_new(fdf);
	//mlx_put_image_to_window(fdf->data->mlx, fdf->data->mlx_window, fdf->data->mlx_image, 0, 0);
	return (0);
}

int			my_expose_hook(t_fdf *fdf)
{
	mlx_destroy_image(fdf->data->mlx, fdf->data->mlx_image);
	if ((fdf->data->mlx_image = mlx_new_image(fdf->data->mlx, 1000, 800)) == NULL)
		ft_error();
	if ((fdf->data->image_string = mlx_get_data_addr(fdf->data->mlx_image, &(fdf->data->bpp), &(fdf->data->s_l), &(fdf->data->endian))) == NULL)
		ft_error();
	open_new(fdf);
	mlx_put_image_to_window(fdf->data->mlx, fdf->data->mlx_window, fdf->data->mlx_image, 0, 0);
	mlx_key_hook(fdf->data->mlx_window, my_key_func, fdf);
	return (0);
}

void		open_new(t_fdf *fdf)
{
	if (fdf->file->first_y != NULL)
		ft_draw_y(fdf);
	if (fdf->file->first_x != NULL)
		ft_draw_x(fdf);
}

int			main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		write(1, "Usage : ./fdf <filename> [ case_size z_size ]\n", 46);
		return (0);
	}
	if ((fdf = (t_fdf*)malloc(sizeof(t_fdf))) == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	fdf->file = ft_get_coord(argv[1]);
	ft_create(fdf);
	open_new(fdf);
	mlx_expose_hook(fdf->data->mlx_window, my_expose_hook, fdf);
	mlx_key_hook(fdf->data->mlx_window, my_key_func, fdf);
	mlx_put_image_to_window(fdf->data->mlx, fdf->data->mlx_window, fdf->data->mlx_image, 0, 0);
	mlx_loop(fdf->data->mlx);
	return (0);
}
