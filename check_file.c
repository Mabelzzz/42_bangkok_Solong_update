/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:38:50 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/12/22 21:43:24 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_gm *game);
void	free_tab(char **tab, int line);
int		file_extension(char *argv, char *fmt);
void	check_file(char *argv, t_gm *game);

void	free_map(t_gm *game)
{
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		free(game->map.area[y]);
		y++;
	}
	free(game->map.area);
	exit(0);
}

void	free_tab(char **tab, int line)
{
	int	y;

	y = 0;
	while (y < line)
	{
		if (tab[y])
			free(tab[y]);
		y++;
	}
	if (tab)
		free(tab);
}

int	file_extension(char *argv, char *fmt)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(argv) - 1;
	while (len >= 0 && i < 4)
	{
		if (argv[len] != fmt[i])
			return (0);
		i++;
		len--;
	}
	return (1);
}

void	check_file(char *argv, t_gm *game)
{
	int	fd;

	if (file_extension(argv, "reb.") == 0)
		error_map("Invalid file name");
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_map("Can not open file map");
	check_ractangular(fd, game);
	get_map(argv, game);
	check_wall(game);
	check_valid_contain(game);
	check_valid_path(game);
	if (game->c != game->map.c || game->e != game->map.e)
		error_map("It's not valid path");
}
