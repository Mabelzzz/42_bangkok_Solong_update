/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:45:30 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/12/22 21:47:09 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_valid_contain(t_gm *game);
void	check_wall(t_gm *game);
void	check_ractangular(int fd, t_gm *game);

void	check_valid_contain(t_gm *game)
{
	if (game->map.p != 1)
		error_map_free("Map has starting position more/less than 1", game);
	if (game->map.e != 1)
		error_map_free("There are Exit more/less than 1", game);
	if (game->map.c < 1)
		error_map_free("Collectible less than 1 on the map", game);
}

void	check_wall(t_gm *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		if (game->map.area[i][0] != '1' ||
			game->map.area[i][game->map.width - 1] != '1')
			error_map_free("not close/surrounded by wall", game);
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.area[0][j] != '1' ||
				game->map.area[game->map.height - 1][j] != '1')
				error_map_free("not close/surrounded by wall", game);
			if (game->map.area[i][j] == 'C' ||
				game->map.area[i][j] == 'P' || game->map.area[i][j] == 'E')
				count_characters(game->map.area[i][j], game);
			j++;
		}
		i++;
	}
}

void	check_ractangular(int fd, t_gm *game)
{
	char	*line;
	int		tmp;

	while (game->map.width)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map.width = (int)ft_strlen(line);
		if (line[game->map.width - 1] == '\n')
			game->map.width--;
		if (game->map.height == 0)
			tmp = game->map.width;
		if (tmp != game->map.width)
			error_map_free("Map is not ractangular", game);
		game->map.height++;
		free(line);
	}
	close(fd);
}
