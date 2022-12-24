/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:31:04 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/12/24 17:22:17 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_gm *game);
void	init_nbr(t_gm *game);
void	init_enemy(t_gm *game);
void	init_map(t_gm *game);
void	init_game(t_gm *game);

void	init_player(t_gm *game)
{
	int		i;
	char	*path;

	i = 0;
	while (i <= 10)
	{
		path = join_path("./texture/gdtm64/g", i);
		game->sp[i] = mlx_xpm_file_to_image(game->init,
				path, &game->w, &game->h);
		free(path);
		i++;
	}
}

void	init_nbr(t_gm *game)
{
	int		i;
	char	*path;

	i = 0;
	while (i < 10)
	{
		path = join_path("./texture/nbr/", i);
		game->nbr[i] = mlx_xpm_file_to_image(game->init,
				path, &game->w, &game->h);
		free(path);
		i++;
	}
}

void	init_enemy(t_gm *game)
{
	int		i;
	char	*path;

	i = 0;
	while (i < 40)
	{
		path = join_path("./texture/enemy/enemy-", i);
		game->enm[i] = mlx_xpm_file_to_image(game->init,
				path, &game->w, &game->h);
		free(path);
		i++;
	}
}

void	init_game(t_gm *game)
{
	init_player(game);
	init_enemy(game);
	init_nbr(game);
	game->fp = 0;
	game->sp_index = 0;
	game->en_index = 0;
	game->grass = mlx_xpm_file_to_image(game->init,
			"./texture/grass1_64.xpm", &game->w, &game->h);
	game->wall = mlx_xpm_file_to_image(game->init,
			"./texture/wall2.xpm", &game->w, &game->h);
	game->collect = mlx_xpm_file_to_image(game->init,
			"./texture/stb64.xpm", &game->w, &game->h);
	game->ext = mlx_xpm_file_to_image(game->init,
			"./texture/exit64.xpm", &game->w, &game->h);
}

void	init_map(t_gm *game)
{
	game->map.area = NULL;
	game->map.width = 1;
	game->map.height = 0;
	game->map.c = 0;
	game->map.p = 0;
	game->map.e = 0;
	game->map.w = 0;
	game->walk = 0;
	game->status = 1;
}
