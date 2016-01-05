/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:06:37 by amineau           #+#    #+#             */
/*   Updated: 2015/12/15 17:16:17 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*ft_new(char *src, int l)
{
	t_map	*map;
	int		i;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		ft_error();
	if (!(map->tab = (char*)malloc(sizeof(char) * 21)))
		ft_error();
	i = 0;
	while (i < 20)
	{
		map->tab[i] = src[i];
		i++;
	}
	map->tab[i] = '\0';
	map->letter = l + 65;
	map->next = NULL;
	map->prev = NULL;
	return (map);
}

void	ft_mapadd(t_map **alst, t_map *new)
{
	t_map	*tmp;

	if (*alst == NULL)
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
}

void	ft_clr_lst(t_map **map)
{
	t_map	*tmp;

	tmp = *map;
	while (tmp)
	{
		free(tmp->tab);
		free(tmp);
		tmp = tmp->next;
	}
	free(map);
}
