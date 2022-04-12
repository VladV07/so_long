/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:21:26 by stapioca          #+#    #+#             */
/*   Updated: 2022/04/12 20:52:48 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, t_game *game)
{
	if (key == 0x00)
	{
		do_key_a(game);
		write(1, "A", 1);
	}
	if (key == 0x01)
	{
		do_key_s(game);
		write(1, "S", 1);
	}
	if (key == 0x02)
	{
		do_key_d(game);
		write(1, "D", 1);
	}
	if (key == 0x0D)
	{
		do_key_w(game);
		write(1, "W", 1);
	}
	if (key == 0x35)
	{
		write(1, " ESC\n", 5);
		err_exit(0);
	}
	render(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = malloc(sizeof(t_game));
		game->sz_textur = 70;
		game->coin = 0;
		game->map = get_map(argv[1], game);
		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, game->sz_textur * game->sz_x, \
					game->sz_textur * game->sz_y, "so_long");
		render(game);
		mlx_key_hook(game->win, deal_key, game);
		mlx_loop(game->mlx);
	}
	else
		write(1, "Wrong args.\n", 12);
	return (0);
}
