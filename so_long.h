/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:29:26 by stapioca          #+#    #+#             */
/*   Updated: 2022/04/12 20:44:40 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h> // ???
# include <stdio.h> // убрать !!!!!!!!!!!!!!!!
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct s_stract
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	int		sz_textur;
	int		sz_x;
	int		sz_y;
	int		x;
	int		y;
	int		coin;
	int		coin_max;
}	t_game;

char	*get_next_line(int fd);
void	err_exit(int flag);
int		my_strlen(const char *str);
int		map_strlen(char **arr);
char	**get_map(char *map_file, t_game *game);
void	render(t_game *game);
void	do_key_w(t_game *game);
void	do_key_s(t_game *game);
void	do_key_d(t_game *game);
void	do_key_a(t_game *game);

#endif