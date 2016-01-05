/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:10:53 by amineau           #+#    #+#             */
/*   Updated: 2015/12/15 17:57:53 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>

# define BUF_SIZE 560

typedef struct	s_map
{
	char			*tab;
	char			letter;
	struct s_map	*next;
	struct s_map	*prev;
}				t_map;

char			*ft_open(char *file, char *buf);
t_map			**ft_create_list(char *str);
t_map			*ft_new(char *src, int l);
void			ft_mapadd(t_map **alst, t_map *new);
void			ft_error();
char			*ft_tab_final(int i);
char			*ft_move_inside(char *map);
void			ft_checker(t_map **map);
int				ft_square_min(t_map **map);
char			*ft_feel_tab(char *tabf, t_map *map, int i);
void			ft_algo(t_map **map);
int				ft_recur(t_map *map, char *tabf);
void			ft_clr_lst(t_map **map);
int				ft_size_tab(char *str);
int				ft_increm(char *str, int i);
void			ft_checker(t_map **map);

#endif
