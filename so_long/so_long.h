/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:29:26 by stapioca          #+#    #+#             */
/*   Updated: 2022/04/07 21:20:00 by stapioca         ###   ########.fr       */
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

char	*get_next_line(int fd);
void	err_exit(int flag);
int		my_strlen(const char *str);
int		map_strlen(char **arr);
char	**get_map(char *map_file);

#endif