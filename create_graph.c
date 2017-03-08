/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:25:02 by kboucaud          #+#    #+#             */
/*   Updated: 2017/03/08 15:25:04 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		ft_graph_size(t_coord *coo)
{
	t_coord		size;

	size.next = NULL;
	size.x = coo->x;
	size.y = coo->y;
	size.z = coo->z;
	while (coo->next != NULL)
	{
		if (coo->x > size.x)
			size.x = coo->x;
		if (coo->y > size.y)
			size.y = coo->y;
		if (coo->z > size.z)
			size.z = coo->z;
		coo = coo->next;
	}
	return (size);
}
