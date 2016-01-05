/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 15:47:11 by amineau           #+#    #+#             */
/*   Updated: 2015/12/15 14:46:57 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_square_min(t_map **map)
{
	t_map	*tmp;
	int		nb;
	int		c;

	tmp = *map;
	nb = 1;
	c = 2;
	while (tmp->next)
	{
		nb++;
		tmp = tmp->next;
	}
	while (nb * 4 > c * c)
		c++;
	return (c);
}

int		ft_increm(char *str, int i)
{
	if (str[i + 1] == '\n')
		return (i + 2);
	else
		return (i + 1);
}

int		ft_size_tab(char *tabf)
{
	int i;

	i = 0;
	while (tabf[i] != '\n')
		i++;
	return (i + 1);
}

char	*ft_feel_tab(char *tabf, t_map *map, int i)
{
	int j;
	int h;
	int	c;

	j = 0;
	c = ft_size_tab(tabf);
	while (map->tab[j + 3])
	{
		h = j + i + (c - 5) * (j / 5);
		if (map->tab[j] == '#')
		{
			if (h > (c * (c - 1) - 2) || tabf[h] != '.')
				return (NULL);
		}
		j = ft_increm(map->tab, j);
	}
	j = 0;
	while (map->tab[j])
	{
		h = j + i + (c - 5) * (j / 5);
		if (map->tab[j] == '#')
			tabf[h] = map->letter;
		j = ft_increm(map->tab, j);
	}
	return (tabf);
}

char	*ft_tab_final(int c)
{
	char	*tabf;
	int		i;

	i = 0;
	if (!(tabf = ft_memalloc(sizeof(char) * (c * (c + 1) + 1))))
		ft_error();
	while (i < c * (c + 1))
	{
		if ((i + 1) % (c + 1) == 0 && i != 0)
			tabf[i] = '\n';
		else
			tabf[i] = '.';
		i++;
	}
	tabf[i] = '\0';
	return (tabf);
}
