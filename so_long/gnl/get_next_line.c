/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:40:57 by stapioca          #+#    #+#             */
/*   Updated: 2021/11/30 19:40:57 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_line_buff(int fd, char *line_buff)
{
	char	*buff;
	int		bytes_read;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(line_buff, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		line_buff = ft_strjoin(line_buff, buff);
	}
	free(buff);
	return (line_buff);
}

char	*get_line(char *line_buff)
{
	size_t		i;
	char		*str;

	i = 0;
	if (!line_buff[i])
		return (NULL);
	while (line_buff[i] && line_buff[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (line_buff[i] && line_buff[i] != '\n')
	{
		str[i] = line_buff[i];
		i++;
	}
	if (line_buff[i] == '\n')
	{
		str[i] = line_buff[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_line_buff(char *line_buff)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = 0;
	while (line_buff[i] && line_buff[i] != '\n')
		i++;
	if (!line_buff[i])
	{
		free(line_buff);
		return (NULL);
	}
	str = malloc(ft_strlen(line_buff) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line_buff[i])
		str[j++] = line_buff[i++];
	str[j] = '\0';
	free(line_buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_buff = read_to_line_buff(fd, line_buff);
	if (!line_buff)
		return (NULL);
	line = get_line(line_buff);
	line_buff = new_line_buff(line_buff);
	return (line);
}
