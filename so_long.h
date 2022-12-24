/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:42:19 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/12/24 16:50:32 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"

# define FRAME_RATE	60

typedef struct s_mtx
{
	char	*path;
	char	**area;
	int		width;
	int		height;
	int		c;
	int		e;
	int		p;
	int		w;
	int		k;
}	t_mtx;

typedef struct s_ch
{
	int		x;
	int		y;
}	t_ch;

typedef struct s_gm
{
	void	*window;
	void	*init;
	void	*sp[11];
	void	*nbr[10];
	void	*enm[40];
	int		c;
	int		e;
	int		w;
	int		h;
	int		walk;
	int		status;
	void	*grass;
	void	*wall;
	void	*collect;
	void	*ext;
	int		fp;
	int		sp_index;
	int		en_index;
	t_mtx	map;
	t_ch	ply;
	t_ch	exit;
	t_ch	enem;
}	t_gm;

// check_file.c
void	free_map(t_gm *game);
void	free_tab(char **tab, int line);
int		file_extension(char *argv, char *fmt);
void	check_file(char *argv, t_gm *game);

// check_map.c
void	check_valid_contain(t_gm *game);
void	check_wall(t_gm *game);
void	check_ractangular(int fd, t_gm *game);

// check_valid_path.c
void	fill(char **tab, t_gm *game, int x, int y);
char	**flood_fill(char **tab, t_gm *game);
void	check_valid_path(t_gm *game);

// create_map.c
char	**duplicate_map(t_gm *game);
void	get_map(char *argv, t_gm *game);

// ft_itoa.c
char	*ft_itoa(int nbr);

// ft_mlx.c
int		loop_hook(t_gm *game);
int		check_can_walk(t_gm *game, int new_x, int new_y);
void	walking(t_gm *game, int new_x, int new_y, int ck);
int		key_hook(int keycode, t_gm *game);

// ft_putnbr_onsc.c
int		count_nbr(int nb);
void	putnbr_onsc(int n, t_gm *game);

// init.c
void	init_player(t_gm *game);
void	init_nbr(t_gm *game);
void	init_enemy(t_gm *game);
void	init_map(t_gm *game);
void	init_game(t_gm *game);

// map_position.c
int		position(t_gm *game, char ch, char axis);
void	get_position(t_gm *game);
void	count_characters(char crt, t_gm *game);

// render.c
void	render_grass(t_gm *game);
void	render_wce(t_gm *game);
void	render_player(t_gm *game);
void	render_enm(t_gm *game, int w, int h);
void	render_enemy(t_gm *game);

// so_long.c
void	open_game(t_gm *game);
int		ft_close(t_gm *game);

// utils.c
void	putstr(char *str);
void	error_map(char *er);
void	error_map_free(char *er, t_gm *game);
char	*copy(char *dst, char *src);
char	*join_path(char *s1, int nb);

#endif
