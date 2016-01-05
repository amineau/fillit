/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:38:59 by amineau           #+#    #+#             */
/*   Updated: 2015/12/15 17:13:38 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_tab_full(char *tabf, char l)
{
	int i;

	i = 0;
	if (!tabf)
		return (0);
	while (tabf[i])
	{
		if (tabf[i] == l)
			return (1);
		i++;
	}
	return (0);
}

void	ft_algo(t_map **map)
{
	int		square;
	char	*tabf;
	char	l;
	t_map	*tmp;

	square = ft_square_min(map);
	tabf = NULL;
	tmp = *map;
	while (tmp)
	{
		tmp->tab = ft_move_inside(tmp->tab);
		if (tmp->next == NULL)
			l = tmp->letter;
		tmp = tmp->next;
	}
	while (ft_tab_full(tabf, l) == 0)
	{
		if (tabf)
			free(tabf);
		tabf = ft_tab_final(square);
		ft_recur(*map, tabf);
		square++;
	}
	ft_putstr(tabf);
}

int		ft_index(char c, char *tabf)
{
	int i;
	int r;
	int	cnt;

	i = 0;
	cnt = 0;
	while (cnt < 4)
	{
		if (tabf[i] == c)
		{
			if (cnt == 0)
				r = i;
			tabf[i] = '.';
			cnt++;
		}
		i++;
	}
	return (r + 1);
}

int		ft_suite_tab(int i, char *tabf, char *map)
{
	int	j;

	j = 0;
	while (map[j] != '#')
		j++;
	while (tabf[i + j] && tabf[i + j] != '.')
		i++;
	return (i);
}

int		ft_recur(t_map *map, char *tabf)
{
	int p;
	int	len;

	p = 0;
	len = (int)ft_strlen(tabf);
	if (map)
	{
		while (p < len)
		{
			if (ft_feel_tab(tabf, map, p))
			{
				if (ft_recur(map->next, tabf) == 1)
					return (1);
				ft_index(map->letter, tabf);
			}
			p = ft_suite_tab(ft_increm(tabf, p), tabf, map->tab);
		}
		return (0);
	}
	return (1);
}
