/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:39:29 by stapioca          #+#    #+#             */
/*   Updated: 2022/04/12 20:08:47 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	blok_if_render(t_game *game, int *pos, int i, int j)
{
	if (game->map[i][j] == 'P')
	{
		game->img = mlx_xpm_file_to_image(game->mlx, "textures/P.xpm", \
						&pos[0], &pos[1]);
		game->x = j;
		game->y = i;
	}
	if (game->map[i][j] == 'C')
		game->img = mlx_xpm_file_to_image(game->mlx, "textures/C.xpm", \
						&pos[0], &pos[1]);
	if (game->map[i][j] == 'E')
		game->img = mlx_xpm_file_to_image(game->mlx, "textures/E.xpm", \
						&pos[0], &pos[1]);
	if (game->map[i][j] == '0')
		game->img = mlx_xpm_file_to_image(game->mlx, "textures/bg0.xpm", \
						&pos[0], &pos[1]);
	if (game->map[i][j] == '1')
		game->img = mlx_xpm_file_to_image(game->mlx, "textures/wall1.xpm", \
						&pos[0], &pos[1]);
}

static void	do_render(t_game *game, int *pos)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = -game->sz_textur;
	while (game->map[i])
	{
		x = -game->sz_textur;
		y = y + game->sz_textur;
		j = -1;
		while (++j < game->sz_x)
		{
			x = x + game->sz_textur;
			blok_if_render(game, pos, i, j);
			mlx_put_image_to_window(game->mlx, game->win, game->img, x, y);
		}
		i++;
	}
}

void	render(t_game *game)
{
	int		*pos;

	pos = (int *)malloc(2);
	if (pos == NULL)
		err_exit(1);
	pos[0] = 0;
	pos[1] = 0;
	game->img = mlx_xpm_file_to_image(game->mlx, "textures/bg.xpm", \
					&pos[0], &pos[1]);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	do_render(game, pos);
	free(pos);
}
