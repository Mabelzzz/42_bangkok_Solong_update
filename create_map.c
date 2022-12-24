/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:37:56 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/12/22 21:49:33 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**duplicate_map(t_gm *game);
void	get_map(char *argv, t_gm *game);

char	**duplicate_map(t_gm *game)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * game->map.height);
	while (i < game->map.height)
	{
		tab[i] = malloc(sizeof(char) * game->map.width + 1);
		if (!tab[i])
		{
			free_tab(tab, i);
			break ;
		}
		tab[i] = copy(tab[i], game->map.area[i]);
		game->map.area[i][game->map.width] = '\0';
		i++;
	}
	return (tab);
}

void	get_map(char *argv, t_gm *game)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_map("can not open file map");
	game->map.area = malloc(sizeof(char *) * game->map.height);
	while (i < game->map.height)
	{
		game->map.area[i] = get_next_line(fd);
		game->map.area[i][game->map.width] = '\0';
		i++;
	}
	close(fd);
}
