/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:39:46 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/12/22 17:13:44 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, t_gm *game, int x, int y);
char	**flood_fill(char **tab, t_gm *game);
void	check_valid_path(t_gm *game);

void	fill(char **tab, t_gm *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map.width
		|| y >= game->map.height || tab[y][x] == '1'
		|| tab[y][x] == 'e' || tab[y][x] == 'c' || tab[y][x] == 'F')
		return ;
	if (tab[y][x] == 'E')
		tab[y][x] = 'e';
	else if (tab[y][x] == 'C')
		tab[y][x] = 'c';
	else
		tab[y][x] = 'F';
	fill(tab, game, x - 1, y);
	fill(tab, game, x, y - 1);
	fill(tab, game, x, y + 1);
	fill(tab, game, x + 1, y);
	return ;
}

char	**flood_fill(char **tab, t_gm *game)
{
	fill(tab, game, game->ply.x, game->ply.y);
	return (tab);
}

void	check_valid_path(t_gm *game)
{
	char	**tab;
	int		i;
	int		j;

	game->c = 0;
	game->e = 0;
	i = 0;
	j = 0;
	tab = duplicate_map(game);
	get_position(game);
	tab = flood_fill(tab, game);
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (tab[i][j] == 'c')
				game->c++;
			if (tab[i][j] == 'e')
				game->e++;
			j++;
		}
		i++;
	}
	free_tab(tab, game->map.height);
}
