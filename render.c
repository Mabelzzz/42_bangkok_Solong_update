/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:58:41 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/12/22 16:03:36 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_grass(t_gm *game);
void	render_wce(t_gm *game);
void	render_player(t_gm *game);
void	render_enm(t_gm *game, int w, int h);
void	render_enemy(t_gm *game);

void	render_grass(t_gm *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			mlx_put_image_to_window(game->init, game->window,
				game->grass, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	render_wce(t_gm *game)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.area[i][j] == '1')
				mlx_put_image_to_window(game->init,
					game->window, game->wall, j * 64, i * 64);
			if (game->map.area[i][j] == 'C')
				mlx_put_image_to_window(game->init, game->window,
					game->collect, j * 64, i * 64);
			if (game->map.area[i][j] == 'E')
				mlx_put_image_to_window(game->init, game->window,
					game->ext, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	render_player(t_gm *game)
{
	if (game->status == 0)
	{
		mlx_put_image_to_window(game->init, game->window,
			game->grass, game->ply.x * 64, game->ply.y * 64);
		mlx_put_image_to_window(game->init, game->window,
			game->sp[10], game->ply.x * 64, game->ply.y * 64);
		return ;
	}
	if (game->fp == FRAME_RATE)
	{
		if (game->sp_index >= 10)
			game->sp_index = 0;
		mlx_put_image_to_window(game->init, game->window,
			game->grass, game->ply.x * 64, game->ply.y * 64);
		mlx_put_image_to_window(game->init, game->window,
			game->sp[game->sp_index], game->ply.x * 64, game->ply.y * 64);
		game->fp = 0;
		game->sp_index++;
	}
	else
		game->fp++;
}

void	render_enm(t_gm *game, int w, int h)
{
	if (game->fp == FRAME_RATE)
	{
		if (game->en_index >= 39)
			game->en_index = 0;
		mlx_put_image_to_window(game->init, game->window,
			game->grass, w * 64, h * 64);
		mlx_put_image_to_window(game->init, game->window,
			game->enm[game->en_index], w * 64, h * 64);
		game->en_index++;
		game->fp = 0;
	}
	else
		game->fp++;
}

void	render_enemy(t_gm *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->map.height)
	{
		w = 0;
		while (w < game->map.width)
		{
			if (game->map.area[h][w] == 'W')
				render_enm(game, w, h);
			w++;
		}
		h++;
	}
}
