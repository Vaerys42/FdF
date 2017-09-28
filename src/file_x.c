/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:37:43 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/27 16:37:45 by kboucaud         ###   ########.fr       */
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

int			**to_tab(char **reader)
{
	int			**tab;
	char		**split;
	int			i;
	int			j;

	tab = (int**)malloc(sizeof(int*) * (reader_len(reader)));
	i = 0;
	while (reader[i] != 0)
	{
		j = 0;
		split = ft_strsplit(reader[i], ' ');
		while (split[j] != NULL)
			j++;
		tab[i] = (int*)malloc(sizeof(int) * (j + 1));
		j = -1;
		while (split[++j] != NULL)
			tab[i][j] = ft_atoi(split[j]);
		tab[i][j] = -1;
		if (reader[i + 1] == 0)
			tab[i][j] = -2;
		i++;
	}
	return (tab);
}

t_file		*ft_create_x_under(int **tab, t_file *file, int x, int len)
{
	int		y;

	y = 0;
	if (x == 0 && y == 0)
	{
		file = ft_new_list_x(0, 0, tab[0][0], file);
		y++;
	}
	while (y <= len)
	{
		file = ft_add_list_x(file, x, y, tab[y][x]);
		y++;
	}
	return (file);
}

t_file		*ft_create_x(char **reader, t_file *file)
{
	int		**tab;
	int		len;
	int		x;

	len = 0;
	x = 0;
	tab = to_tab(reader);
	while (tab[len][x] != -1 && tab[len][x] != -2)
		x++;
	while (tab[len][x] != -2)
		len++;
	x = 0;
	if (len == 0)
		return (ft_return_len(file));
	while (tab[len][x] != -1 && tab[len][x] != -2)
	{
		file = ft_create_x_under(tab, file, x, len);
		x++;
	}
	free(tab);
	free(reader);
	return (file);
}
