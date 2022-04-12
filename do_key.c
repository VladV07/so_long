/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:43:02 by stapioca          #+#    #+#             */
/*   Updated: 2022/04/12 20:43:08 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_key_a(t_game *game)
{
	if (game->map[game->y][game->x - 1] == '0')
	{
		game->map[game->y][game->x] = '0';
		game->map[game->y][game->x - 1] = 'P';
	}
	if (game->map[game->y][game->x - 1] == 'C')
	{
		game->map[game->y][game->x] = '0';
		game->map[game->y][game->x - 1] = 'P';
		game->coin++;
	}
	if (game->map[game->y][game->x - 1] == 'E')
	{
		if (game->coin == game->coin_max)
		{
			game->map[game->y][game->x] = '0';
			game->map[game->y][game->x - 1] = 'P';
		}
	}
}

void	do_key_s(t_game *game)
{
	if (game->map[game->y + 1][game->x] == '0')
	{
		game->map[game->y][game->x] = '0';
		game->map[game->y + 1][game->x] = 'P';
	}
	if (game->map[game->y + 1][game->x] == 'C')
	{
		game->map[game->y][game->x] = '0';
		game->map[game->y + 1][game->x] = 'P';
		game->coin++;
	}
	if (game->map[game->y + 1][game->x] == 'E')
	{
		if (game->coin == game->coin_max)
		{
			game->map[game->y][game->x] = '0';
			game->map[game->y + 1][game->x] = 'P';
		}
	}
}

void	do_key_d(t_game *game)
{
	if (game->map[game->y][game->x + 1] == '0')
	{
		game->map[game->y][game->x] = '0';
		game->map[game->y][game->x + 1] = 'P';
	}
	if (game->map[game->y][game->x + 1] == 'C')
	{
		game->map[game->y][game->x] = '0';
		game->map[game->y][game->x + 1] = 'P';
		game->coin++;
	}
	if (game->map[game->y][game->x + 1] == 'E')
	{
		if (game->coin == game->coin_max)
		{
			game->map[game->y][game->x] = '0';
			game->map[game->y][game->x + 1] = 'P';
		}
	}
}

void	do_key_w(t_game *game)
{
	if (game->map[game->y - 1][game->x] == '0')
	{
		game->map[game->y][game->x] = '0';
		game->map[game->y - 1][game->x] = 'P';
	}
	if (game->map[game->y - 1][game->x] == 'C')
	{
		game->map[game->y][game->x] = '0';
		game->map[game->y - 1][game->x] = 'P';
		game->coin++;
	}
	if (game->map[game->y - 1][game->x] == 'E')
	{
		if (game->coin == game->coin_max)
		{
			game->map[game->y][game->x] = '0';
			game->map[game->y - 1][game->x] = 'P';
		}
	}
}
