/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:56:14 by rbejot            #+#    #+#             */
/*   Updated: 2015/12/15 18:52:39 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_form_checker(int i, int j, t_map *tmp)
{
	while (tmp->tab[++i] != '\0')
	{
		if (tmp->tab[i] == '#')
		{
			if ((j < 2 && ((tmp->tab[i + 1] == '#' || tmp->tab[i + 5] == '#')
			|| (tmp->tab[i + 4] == '#' && tmp->tab[i - 1] == '#')))
			|| (j == 2 && ((tmp->tab[i + 1] == '#' || tmp->tab[i + 5] == '#')
			|| (tmp->tab[i - 6] == '#' || tmp->tab[i - 1] == '#')))
			|| (j == 3 && (tmp->tab[i - 5] == '#' || tmp->tab[i - 1] == '#')))
				j++;
			else
				ft_error();
		}
		else if (tmp->tab[i] != '.' && tmp->tab[i] != '\n')
			ft_error();
	}
	return (j);
}

void	ft_checker(t_map **map)
{
	t_map		*tmp;
	int			i;
	int			j;

	tmp = *map;
	while (tmp)
	{
		i = -1;
		j = 0;
		j = ft_form_checker(i, j, tmp);
		if (j != 4)
			ft_error();
		tmp = tmp->next;
	}
}
