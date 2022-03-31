#include "so_long.h"

void	err_exit(int flag)
{
	if (flag)
		write (2, "Error\n", 6);
	exit (0);
}
/*
int	accept_input(char *str)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return (1);
		//if (!parse_commands(line, str))
			//return (0);
		free (line);
	}
}*/

int	deal_key(int key, void *param)
{
	//(void)key;
	(void)param;
	//printf("key = %d", key);
	if (key == 0x00)
		write(1, "A", 1);
	if (key == 0x01)
		write(1, "S", 1);
	if (key == 0x02)
		write(1, "D", 1);
	if (key == 0x0D)
		write(1, "W", 1);
	return (0);
}

int	count_line_map_file(char *map_file)
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

char	**map_malloc(char *map_file)
{
	char	**map;
	int		count_line;

	count_line = count_line_map_file(map_file);
	map = malloc(sizeof(char *) * count_line + 1);
	return (map);
}

char	**get_map(char *map_file)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	i = 0;
	map = map_malloc(map_file);
	if (map == NULL)
		return (NULL);
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;

	if (argc == 2)
	{
		map = get_map(argv[1]);

		char tp;
		int i, j;
		for (i = 0; i < 6; i++)
		{
			for (j = 0; j < 9; j++)
			{
				tp = map[i][j];
				printf("%c", tp);
			}
			printf("\n");
		}
	/*	mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 500, 500, "so_long");
		mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
		mlx_key_hook(win_ptr, deal_key, (void *)0);
		mlx_loop(mlx_ptr);*/
	}
	else
		write(1, "Wrong args.\n", 12);
	return (0);
}
