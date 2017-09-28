/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 18:34:23 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/27 18:34:25 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		more_alt(t_fdf *fdf)
{
	fdf->file->current = fdf->file->first_x;
	while (fdf->file->current->next != NULL)
	{
		if (fdf->file->current->update != 0)
			fdf->file->current->z += 1;
		fdf->file->current->color = get_color(fdf->file->current->z);
		fdf->file->current = fdf->file->current->next;
	}
	fdf->file->current = fdf->file->first_y;
	while (fdf->file->current->next != NULL)
	{
		if (fdf->file->current->update != 0)
			fdf->file->current->z += 1;
		fdf->file->current->color = get_color(fdf->file->current->z);
		fdf->file->current = fdf->file->current->next;
	}
}

void		less_alt(t_fdf *fdf)
{
	fdf->file->current = fdf->file->first_x;
	while (fdf->file->current->next != NULL)
	{
		if (fdf->file->current->update != 0)
			fdf->file->current->z -= 1;
		fdf->file->current->color = get_color(fdf->file->current->z);
		fdf->file->current = fdf->file->current->next;
	}
	fdf->file->current = fdf->file->first_y;
	while (fdf->file->current->next != NULL)
	{
		if (fdf->file->current->update != 0)
			fdf->file->current->z -= 1;
		fdf->file->current->color = get_color(fdf->file->current->z);
		fdf->file->current = fdf->file->current->next;
	}
}
