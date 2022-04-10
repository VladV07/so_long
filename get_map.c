/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:21:03 by stapioca          #+#    #+#             */
/*   Updated: 2022/04/10 21:17:26 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_char(char ch, int flag)
{
	static int	count_e;
	static int	count_p;
	static int	count_c;

	if (flag == 1)
		if (count_e != 1 || count_p != 1 || count_c < 1)
			err_exit(1);
	if (ch == '0' || ch == '1' || ch == 'C' || ch == 'E' || ch == 'P')
	{
		if (ch == 'C')
			count_c++;
		if (ch == 'E')
			count_e++;
		if (ch == 'P')
			count_p++;
		if (count_e > 1 || count_p > 1)
			return (0);
		return (1);
	}
	return (0);
}

static void	valid_map(char	**map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		game->sz_x = my_strlen(map[i]);
		game->sz_y = map_strlen(map);
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (valid_char(map[i][j], 0) == 0)
				err_exit(1);
			if (i == 0 && map[i][j] != '1')
				err_exit(1);
			if (map[i][0] != '1' || map[i][game->sz_x - 1] != '1')
				err_exit(1);
			if (i == (game->sz_y - 1) && map[i][j] != '1')
				err_exit(1);
			j++;
		}
		i++;
	}
	valid_char('a', 1);
}

static int	count_line_map_file(char *map_file)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	return (count);
}

static char	**map_malloc(char *map_file)
{
	char	**map;
	int		count_line;

	count_line = count_line_map_file(map_file);
	map = malloc(sizeof(char *) * count_line + 1);
	if (map == NULL)
		err_exit(1);
	return (map);
}

char	**get_map(char *map_file, t_game *game)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	i = 0;
	map = map_malloc(map_file);
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (my_strlen(map[i]) != my_strlen(line))
			err_exit(1);
		i++;
	}
	i++;
	map[i] = NULL;
	valid_map(map, game);
	close(fd);
	return (map);
}
