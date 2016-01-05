/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:08:04 by amineau           #+#    #+#             */
/*   Updated: 2015/12/09 16:35:07 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_open(char *file, char *buf)
{
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error();
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (close(fd) == -1)
		ft_error();
	return (buf);
}
