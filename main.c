/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:17:00 by amineau           #+#    #+#             */
/*   Updated: 2015/12/15 17:19:05 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_map	**tetri;
	char	buf[BUF_SIZE];

	if (ac != 2)
		ft_error();
	tetri = ft_create_list(ft_open(av[1], buf));
	ft_checker(tetri);
	ft_algo(tetri);
	ft_clr_lst(tetri);
	return (0);
}
