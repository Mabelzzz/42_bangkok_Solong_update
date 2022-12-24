/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:15:05 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/12/22 15:49:27 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		loop_hook(t_gm *game);
int		check_can_walk(t_gm *game, int new_x, int new_y);
void	walking(t_gm *game, int new_x, int new_y, int ck);
int		key_hook(int keycode, t_gm *game);

int	loop_hook(t_gm *game)
{
	render_enemy(game);
	render_player(game);
	return (0);
}

int	check_can_walk(t_gm *game, int new_x, int new_y)
{
	char	pst;

	pst = game->map.area[new_y][new_x];
	if (pst == '0' || pst == 'C' || pst == 'P')
	{
		if (pst == 'C')
			game->map.c--;
		return (1);
	}
	if (pst == 'E' && game->map.c == 0)
	{
		putstr("----- You are the WINNER -----\n");
		free_map(game);
	}
	if (pst == 'E')
		return (2);
	if (pst == 'W')
		return (3);
	return (0);
}

void	walking(t_gm *game, int new_x, int new_y, int ck)
{
	game->walk++;
	putnbr_onsc(game->walk, game);
	if (game->map.area[game->ply.y][game->ply.x] != 'E')
	{
		game->map.area[game->ply.y][game->ply.x] = '0';
		mlx_put_image_to_window(game->init, game->window,
			game->grass, game->ply.x * 64, game->ply.y * 64);
	}
	else
	{
		mlx_put_image_to_window(game->init, game->window,
			game->grass, game->ply.x * 64, game->ply.y * 64);
		mlx_put_image_to_window(game->init, game->window,
			game->ext, game->ply.x * 64, game->ply.y * 64);
	}
	if (ck == 1 || ck == 3)
		game->map.area[new_y][new_x] = 'P';
	if (ck == 3)
	{
		putstr("----- You are the LOSER -----\n");
		game->status = 0;
	}
	game->ply.x = new_x;
	game->ply.y = new_y;
}

int	key_hook(int keycode, t_gm *game)
{
	int	new_x;
	int	new_y;
	int	ck;

	new_x = game->ply.x;
	new_y = game->ply.y;
	if (game->status == 0 || keycode == 53)
	{
		putstr("----- Game Over -----\n");
		free_map(game);
	}
	else if (keycode == 0 || keycode == 123)
		new_x--;
	else if (keycode == 1 || keycode == 125)
		new_y++;
	else if (keycode == 2 || keycode == 124)
		new_x++;
	else if (keycode == 13 || keycode == 126)
		new_y--;
	else
		return (0);
	ck = check_can_walk(game, new_x, new_y);
	if (ck > 0 && new_x >= 0 && new_y >= 0)
		walking(game, new_x, new_y, ck);
	return (ck);
}
