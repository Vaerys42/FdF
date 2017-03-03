/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:50:39 by kboucaud          #+#    #+#             */
/*   Updated: 2017/03/02 14:50:44 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strnjoin(char const *s1, char const *s2, int size)
{
	char	*new;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	if ((new = (char*)malloc(sizeof(char) * (i + size + 1))) == NULL)
		return (new);
	j = 0;
	while (s1[j] != 0)
	{
		new[j] = s1[j];
		j++;
	}
	i = 0;
	while (i < size)
	{
		new[j + i] = s2[i];
		i++;
	}
	new[j + i] = 0;
	return (new);
}
