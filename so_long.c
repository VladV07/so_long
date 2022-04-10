/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:21:26 by stapioca          #+#    #+#             */
/*   Updated: 2022/04/10 21:20:30 by stapioca         ###   ########.fr       */
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
	t_game	*game;

	if (argc == 2)
	{
		game = malloc(sizeof(t_game));
		game->sz_textur = 70;
		game->map = get_map(argv[1], game);
		printf("game->sz_x = %d\n",game->sz_x);
		printf("game->sz_y = %d\n",game->sz_y);
		printf("game->map[i][j] = %c\n",game->map[0][0]);
		game->mlx = mlx_init();
		printf("game->map[i][j] = %c\n",game->map[0][0]);
		game->win = mlx_new_window(game->mlx, game->sz_textur * game->sz_x, game->sz_textur * game->sz_y, "so_long");

		int *pos;
		pos =(int *)malloc(2);
		pos[0] = 0;
		pos[1] = 0;
		//img_ptr = mlx_new_image (mlx_ptr, 100, 100);
		//img_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/P->xpm", &pos[0], &pos[1]);
		game->img = mlx_xpm_file_to_image(game->mlx, "textures/bg.xpm", &pos[0], &pos[1]);
		mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
		//mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 10, 10);
		printf("game->sz_x = %d\n",game->sz_x);
		int i = 0, j;
		//for (i = 0; i < 6; i++)
		int x, y;
		y = -game->sz_textur;
		while (game->map[i])
		{
			x = -game->sz_textur;
			y = y + game->sz_textur;
			for (j = 0; j < game->sz_x; j++)
			{
				x = x + game->sz_textur;
				if (game->map[i][j] == 'P')
					game->img = mlx_xpm_file_to_image(game->mlx, "textures/P.xpm", &pos[0], &pos[1]);
				if (game->map[i][j] == 'C')
					game->img = mlx_xpm_file_to_image(game->mlx, "textures/C.xpm", &pos[0], &pos[1]);
				if (game->map[i][j] == 'E')
					game->img = mlx_xpm_file_to_image(game->mlx, "textures/E.xpm", &pos[0], &pos[1]);
				if (game->map[i][j] == '0')
					game->img = mlx_xpm_file_to_image(game->mlx, "textures/bg0.xpm", &pos[0], &pos[1]);
				if (game->map[i][j] == '1')
					game->img = mlx_xpm_file_to_image(game->mlx, "textures/wall1.xpm", &pos[0], &pos[1]);
				mlx_put_image_to_window(game->mlx, game->win, game->img, x, y);
			}
			//printf("\n");
			i++;
		}
		
		//mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
		mlx_key_hook(game->win, deal_key, (void *)0);
		mlx_loop(game->mlx);
	}
	else
		write(1, "Wrong args.\n", 12);
	return (0);
}
