/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:59:14 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/12/24 16:56:39 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putstr(char *str);
void	error_map(char *er);
void	error_map_free(char *er, t_gm *game);
char	*copy(char *dst, char *src);
char	*join_path(char *s1, int nb);

void	putstr(char *str)
{
	int	s;

	if (!str)
		return ;
	s = 0;
	while (str[s] != '\0')
	{
		write(1, &str[s], 1);
		s++;
	}
}

void	error_map(char *er)
{
	putstr("Error\n");
	putstr(er);
	write(1, "\n", 1);
	exit(0);
}

void	error_map_free(char *er, t_gm *game)
{
	putstr("Error\n");
	putstr(er);
	write(1, "\n", 1);
	free_map(game);
	exit(0);
}

char	*copy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*join_path(char *s1, int nb)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	char	*nbr;

	s1_len = (int)ft_strlen(s1);
	s2_len = count_nbr(nb);
	str = malloc(sizeof(char) * (s1_len + s2_len + 5));
	if (!str)
		return (NULL);
	nbr = ft_itoa(nb);
	copy(str, s1);
	copy(&str[s1_len], nbr);
	copy(&str[s1_len + s2_len], ".xpm");
	free(nbr);
	return (str);
}
