/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:55:34 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/12/22 15:58:13 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		position(t_gm *game, char ch, char axis);
void	get_position(t_gm *game);
void	count_characters(char crt, t_gm *game);

int	position(t_gm *game, char ch, char axis)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.area[i][j] == ch)
			{
				if (axis == 'x')
					return (j);
				if (axis == 'y')
					return (i);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	get_position(t_gm *game)
{
	game->ply.x = position(game, 'P', 'x');
	game->ply.y = position(game, 'P', 'y');
	game->exit.x = position(game, 'E', 'x');
	game->exit.y = position(game, 'E', 'y');
}

void	count_characters(char crt, t_gm *game)
{
	if (crt == 'C')
		game->map.c++;
	if (crt == 'P')
		game->map.p++;
	if (crt == 'E')
		game->map.e++;
	if (crt == 'W')
		game->map.w++;
}
