/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:58:59 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/12/24 16:49:33 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_game(t_gm *game);
int		ft_close(t_gm *game);

int	ft_close(t_gm *game)
{
	mlx_destroy_window(game->init, game->window);
	free_map(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_gm	game;

	if (argc != 2)
		error_map("Invalid argument");
	init_map(&game);
	check_file(argv[1], &game);
	open_game(&game);
	if (game.map.area)
		free_map(&game);
	return (0);
}

void	open_game(t_gm *game)
{
	putstr("----- Game Starto -----\n");
	game->init = mlx_init();
	game->window = mlx_new_window(game->init, game->map.width * 64,
			game->map.height * 64, "so_long");
	init_game(game);
	render_grass(game);
	render_wce(game);
	mlx_hook(game->window, 17, 1L << 0, ft_close, game);
	mlx_key_hook(game->window, key_hook, game);
	mlx_loop_hook(game->init, loop_hook, game);
	mlx_loop(game->init);
}
