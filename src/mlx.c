/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:55:55 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/27 18:21:31 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		ft_create(t_fdf *fdf)
{
	if ((fdf->data = (t_data*)malloc(sizeof(t_data))) == NULL)
		ft_error();
	if ((fdf->data->mlx = mlx_init()) == NULL)
		ft_error();
	if ((fdf->data->mlx_window = mlx_new_window(fdf->data->mlx, 1000, 800,
	"Fdf")) == NULL)
		ft_error();
	if ((fdf->data->mlx_image = mlx_new_image(fdf->data->mlx, 1000, 800))
	== NULL)
		ft_error();
	if ((fdf->data->image_string = mlx_get_data_addr(fdf->data->mlx_image,
	&(fdf->data->bpp), &(fdf->data->s_l), &(fdf->data->endian))) == NULL)
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
	if (key == 53)
		exit(1);
	if (key == 124)
		fdf->key->x += 1;
	if (key == 123 && fdf->key->x > 0)
		fdf->key->x -= 1;
	if (key == 125)
		fdf->key->y += 1;
	if (key == 126 && fdf->key->y > 0)
		fdf->key->y -= 1;
	if (key == 69)
		more_alt(fdf);
	if (key == 78)
		less_alt(fdf);
	mlx_destroy_image(fdf->data->mlx, fdf->data->mlx_image);
	if ((fdf->data->mlx_image = mlx_new_image(fdf->data->mlx, 1000, 800))
	== NULL)
		ft_error();
	if ((fdf->data->image_string = mlx_get_data_addr(fdf->data->mlx_image,
	&(fdf->data->bpp), &(fdf->data->s_l), &(fdf->data->endian))) == NULL)
		ft_error();
	open_new(fdf);
	mlx_put_image_to_window(fdf->data->mlx, fdf->data->mlx_window,
	fdf->data->mlx_image, 0, 0);
	return (0);
}

int			my_expose_hook(t_fdf *fdf)
{
	mlx_destroy_image(fdf->data->mlx, fdf->data->mlx_image);
	if ((fdf->data->mlx_image = mlx_new_image(fdf->data->mlx, 1000, 800))
	== NULL)
		ft_error();
	if ((fdf->data->image_string = mlx_get_data_addr(fdf->data->mlx_image,
	&(fdf->data->bpp), &(fdf->data->s_l), &(fdf->data->endian))) == NULL)
		ft_error();
	open_new(fdf);
	mlx_put_image_to_window(fdf->data->mlx, fdf->data->mlx_window,
	fdf->data->mlx_image, 0, 0);
	mlx_key_hook(fdf->data->mlx_window, my_key_func, fdf);
	return (0);
}
