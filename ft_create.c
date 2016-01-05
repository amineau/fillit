/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:40:20 by amineau           #+#    #+#             */
/*   Updated: 2015/12/15 17:57:08 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	**ft_create_list(char *str)
{
	int		i;
	int		mod;
	int		div;
	t_map	**tetri;

	i = -1;
	if (!str[0])
		ft_error();
	if (!(tetri = ft_memalloc(sizeof(t_map*))))
		ft_error();
	while (str[++i])
	{
		mod = i % 21;
		div = i / 21;
		if (((mod == 4 || mod == 9 || mod == 14 || mod == 19
				|| mod == 20) && str[i] != '\n')
				|| (!(mod == 4 || mod == 9 || mod == 14 || mod == 19
				|| mod == 20) && str[i] == '\n') || div > 25)
			ft_error();
		if (mod == 0)
			ft_mapadd(tetri, ft_new(str + i, div));
	}
	if (i % 21 != 20)
		ft_error();
	return (tetri);
}
