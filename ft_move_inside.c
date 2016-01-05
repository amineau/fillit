/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_inside.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:57:10 by amineau           #+#    #+#             */
/*   Updated: 2015/12/06 10:44:03 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_move_x(char *map)
{
	int	x;
	int	i;

	i = 0;
	while (map[i % 19] != '#')
		i += 5;
	x = (i % 19) % 5;
	return (x);
}

int		ft_move_y(char *map)
{
	int	y;
	int	i;

	i = 0;
	while (map[i] != '#')
		i++;
	y = i / 5;
	return (y);
}

char	*ft_move_inside(char *map)
{
	int	x;
	int	y;
	int	i;

	x = ft_move_x(map);
	y = ft_move_y(map);
	if (x != 0 || y != 0)
	{
		i = 0;
		while (map[i])
		{
			if (map[i] == '#')
			{
				map[i] = '.';
				map[i - (x) - (y * 5)] = '#';
			}
			i++;
		}
	}
	return (map);
}
