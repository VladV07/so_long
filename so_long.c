/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:21:26 by stapioca          #+#    #+#             */
/*   Updated: 2022/04/07 20:42:29 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;

	if (argc == 2)
	{
		map = get_map(argv[1]);
		char tp;
		int i = 0, j;
		//for (i = 0; i < 6; i++)
		while (map[i])
		{
			for (j = 0; j < 9; j++)
			{
				tp = map[i][j];
				printf("%c", tp);
			}
			printf("\n");
			i++;
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
