/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_onsc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:53:22 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/12/22 17:23:43 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		power_ten(int n);
int		count_nbr(int nb);
void	show_nbr(int nb, int count, t_gm *game);
void	putnbr_onsc(int n, t_gm *game);

int	power_ten(int n)
{
	int	p;

	p = 1;
	if (n != 0)
	{
		while (n >= 1)
		{
			p *= 10;
			n--;
		}
		return (p);
	}
	else
	{
		return (1);
	}
}

int	count_nbr(int nb)
{
	int	c;

	c = 0;
	while (c <= 10)
	{
		nb = nb / 10;
		c++;
		if (nb == 0)
			break ;
	}
	return (c);
}

void	show_nbr(int nb, int count, t_gm *game)
{
	int		n;
	char	ch;
	int		y;

	y = 0;
	n = 0;
	while (count >= 1)
	{
		n = nb / power_ten(count - 1);
		mlx_put_image_to_window(game->init, game->window,
			game->wall, y * 64, 0);
		mlx_put_image_to_window(game->init, game->window,
			game->nbr[n % 10], y * 64, 0);
		ch = n % 10 + '0';
		write(1, &ch, 1);
		y++;
		count--;
	}
}

void	putnbr_onsc(int n, t_gm *game)
{
	if (n >= 0 && n <= 2147483647)
	{
		putstr("step --> ");
		show_nbr(n, count_nbr(n), game);
		write(1, "\n", 1);
	}
}
