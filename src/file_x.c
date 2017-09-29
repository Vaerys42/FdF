/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:37:43 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/29 16:04:47 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_file		*ft_new_list_x(int x, int y, int z, t_file *file)
{
	t_one		*ini;

	ini = (t_one*)malloc(sizeof(*ini));
	if (!ini)
		ft_error();
	ini->x = x;
	ini->y = y;
	ini->z = z;
	ini->color = get_color(z);
	ini->update = 0;
	if (z != 0)
		ini->update = 1;
	ini->next = NULL;
	file->first_x = ini;
	file->current = ini;
	return (file);
}

t_file		*ft_add_list_x(t_file *file, int x, int y, int z)
{
	t_one		*new;

	if (!file)
		ft_error();
	new = (t_one*)malloc(sizeof(*new));
	if (!new)
		ft_error();
	new->x = x;
	new->y = y;
	new->z = z;
	new->color = get_color(z);
	new->update = 0;
	if (z != 0)
		new->update = 1;
	new->next = NULL;
	while (file->current->next != NULL)
		file->current = file->current->next;
	file->current->next = new;
	if (file->first_x->next == NULL)
		file->first_x->next = file->current->next;
	return (file);
}

char		***ft_create_tab(char **reader, int len)
{
	char	***tab;
	int		i;

	tab = (char***)malloc(sizeof(char**) * (len + 1));
	tab[len] = NULL;
	i = 0;
	while (reader[i] != 0)
	{
		tab[i] = ft_strsplit(reader[i], ' ');
		i++;
	}
	return (tab);
}

void		ft_create_x(char **reader, t_file *file)
{
	int		x;
	int		y;
	int		len;
	char	***tab;

	x = -1;
	y = 0;
	len = 0;
	while (reader[len] != 0)
		len++;
	tab = ft_create_tab(reader, len + 1);
	while (tab[0][++x] != 0)
	{
		if (y == 0 && x == 0)
		{
			ft_new_list_x(0, 0, ft_atoi(tab[0][0]), file);
			y++;
		}
		while (y < len)
		{
			ft_add_list_x(file, x, y, ft_atoi(tab[y][x]));
			y++;
		}
		y = 0;
	}
}
