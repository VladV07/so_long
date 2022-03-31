/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:41:32 by stapioca          #+#    #+#             */
/*   Updated: 2021/11/30 19:41:32 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*read_to_line_buff(int fd, char *line_buff);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *line_buff, char *buff);
size_t	ft_strlen(char *s);
char	*get_line(char *line_buff);
char	*new_line_buff(char *line_buff);

#endif
