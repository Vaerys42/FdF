/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:49:23 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/27 16:49:30 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			reader_len(char **reader)
{
	int		i;

	i = 0;
	while (reader[i] != 0)
		i++;
	return (i);
}

t_file		*ft_return_len(t_file *file)
{
	file->first_x = NULL;
	return (file);
}

int			ft_line_len(t_file *file)
{
	int		i;

	i = 0;
	while (file->current->y == file->current->next->y
	&& file->current->next != NULL)
	{
		i++;
		file->current = file->current->next;
	}
	return (i);
}
