/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:39:05 by mprokope          #+#    #+#             */
/*   Updated: 2026/02/12 17:27:06 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_W 1920
# define WIN_H 1080
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

typedef struct s_array
{
	int		g;
	int		h;
	int		f;
	int		closed;
}			t_array;

typedef struct s_xy
{
	int		x;
	int		y;
}			t_xy;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_coll;
	void	*img_player;
	void	*img_exit;
	void	*img_exit_player;
	void	*img_exit_open;
	int		x;
	int		y;
	int		n;
	char	**matrix;
	t_xy	exit_pos;
}			t_game;
// MLX
void		init_stuff(t_game *g);
void		swag(t_game *g, t_xy now, int y, int x);
void		cont_load_img(t_game *g);
void		insanity(int fuck[8]);
t_xy		count_smth(char **matrix);
void		*render_walls(t_game g, char ***matrix);
int			win_size(int x, int num);
void		*render_back(t_game g, char ***matrix);
void		*render_player(t_game g, char ***matrix, int a);
void		*render_exit(t_game g, char ***matrix, int a);
void		*render_coll(t_game g, char ***matrix);
void		load_img(t_game *g);
void		render_map(t_game *g, char ***matrix, int a);
int			close_win(t_game *g);
void		swap(t_game *g, t_xy now, int y, int x);
void		move(int move, t_game *g);
int			key_hook(int keycode, t_game *g);

// ASTAR
int			coll_check(char **matrix);
int			side_char_check(char *li);
int			exit_check(char *line);
int			coin_check(char *line);
int			player_check(char *line);
int			border_check(char **matrix);
int			check_middle(char *line);
int			check_line(char *line);
int			rect_check(char **matrix);
int			one(char c);
int			astar(char **matrix, int coll_n, char symbl);
void		astar_helper(t_array ***array, char **matrix, t_xy cur,
				int cords[]);
int			lowest_f(t_array **ar, char **ma, t_xy *cord);
int			manhattan(t_xy first, t_xy second);
t_xy		find_and_skip(char **matrix, char c, int skip);
int			h_of(char **matrix);
void		init_vars(t_array *array, char **matrix, int x, int y);
t_array		**init_arr(char **matrix);
int			coll_n(char **matrix);
int			check_ava(char **matrix);
// OTHER
void		ft_putnbr_fd(int n, int fd);
int			check_ext(char *line);
void		strip_nw(char ***matrix);
int			count(char **argv);
void		nuke(void **matrix);
int			wr(char *str, int fd);
int			ft_strlen(char *line);
//void		print_pos(t_xy pos);
int			astar(char **matrix, int coll_n, char symbl);
void		move_player(char ***matrix, t_xy old_pos, int y, int x);
int			check_1(char **matrix, t_xy pos);
t_xy		pos(char **matrix, char c);
int			check(char **matrix);

#endif
