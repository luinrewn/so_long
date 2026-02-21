/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 06:11:06 by mprokope          #+#    #+#             */
/*   Updated: 2026/02/12 17:14:17 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*render_back(t_game g, char ***matrix)
{
	void	*img;
	int		xx;
	int		yy;
	int		i;
	int		j;

	img = g.img_floor;
	yy = 0;
	i = 0;
	while (yy + g.y < WIN_H && (*matrix)[i])
	{
		xx = 0;
		j = 0;
		while (xx + g.x < WIN_W && (*matrix)[i][j])
		{
			mlx_put_image_to_window(g.mlx, g.win, img, xx, yy);
			xx += g.x;
			j++;
		}
		yy += g.y;
		i++;
	}
	return (img);
}

void	*render_player(t_game g, char ***matrix, int a)
{
	void	*img;
	t_xy	pos;

	img = g.img_player;
	if (a)
	{
		pos = find_and_skip(*matrix, 'P', 0);
		mlx_put_image_to_window(g.mlx, g.win, img, win_size(pos.x, 32),
			win_size(pos.y, 46));
	}
	return (img);
}

void	*render_exit(t_game g, char ***matrix, int a)
{
	void	*img;

	if (!(coll_n(*matrix)))
		img = g.img_exit_open;
	else if (!a)
		img = g.img_exit_player;
	else
		img = g.img_exit;
	mlx_put_image_to_window(g.mlx, g.win, img, win_size(g.exit_pos.x, 32),
		win_size(g.exit_pos.y, 46));
	return (img);
}

void	*render_coll(t_game g, char ***matrix)
{
	void	*img;
	t_xy	pos;
	int		n;

	img = g.img_coll;
	n = coll_n(*matrix);
	while (n--)
	{
		pos = find_and_skip(*matrix, 'C', n);
		mlx_put_image_to_window(g.mlx, g.win, img, win_size(pos.x, 32),
			win_size(pos.y, 46));
	}
	return (img);
}

void	load_img(t_game *g)
{
	g->img_wall = mlx_xpm_file_to_image(g->mlx, "images/Box.xpm", &g->x, &g->y);
	if (!g->img_wall)
		exit((nuke((void **)g->matrix), g->matrix = NULL, close_win(g), -1));
	g->img_floor = mlx_xpm_file_to_image(g->mlx, "images/floor.xpm", &g->x,
			&g->y);
	if (!g->img_floor)
		exit((nuke((void **)g->matrix), g->matrix = NULL, close_win(g), -1));
	g->img_coll = mlx_xpm_file_to_image(g->mlx, "images/drone.xpm", &g->x,
			&g->y);
	if (!g->img_coll)
		exit((nuke((void **)g->matrix), g->matrix = NULL, close_win(g), -1));
	g->img_player = mlx_xpm_file_to_image(g->mlx, "images/director.xpm", &g->x,
			&g->y);
	if (!g->img_player)
		exit((nuke((void **)g->matrix), g->matrix = NULL, close_win(g), -1));
	g->img_exit = mlx_xpm_file_to_image(g->mlx, "images/door.xpm", &g->x,
			&g->y);
	if (!g->img_exit)
		exit((nuke((void **)g->matrix), g->matrix = NULL, close_win(g), -1));
	g->img_exit_open = mlx_xpm_file_to_image(g->mlx, "images/open_door.xpm",
			&g->x, &g->y);
	if (!g->img_exit_open)
		exit((nuke((void **)g->matrix), g->matrix = NULL, close_win(g), -1));
	cont_load_img(g);
}
