/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 22:32:05 by mprokope          #+#    #+#             */
/*   Updated: 2026/02/12 17:23:16 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *g, char ***matrix, int a)
{
	render_back(*g, matrix);
	render_walls(*g, matrix);
	render_player(*g, matrix, a);
	render_exit(*g, matrix, a);
	render_coll(*g, matrix);
}

int	close_win(t_game *g)
{
	if (g->matrix)
		nuke((void **)g->matrix);
	if (g->img_floor)
		mlx_destroy_image(g->mlx, g->img_floor);
	if (g->img_wall)
		mlx_destroy_image(g->mlx, g->img_wall);
	if (g->img_coll)
		mlx_destroy_image(g->mlx, g->img_coll);
	if (g->img_player)
		mlx_destroy_image(g->mlx, g->img_player);
	if (g->img_exit)
		mlx_destroy_image(g->mlx, g->img_exit);
	if (g->img_exit_open)
		mlx_destroy_image(g->mlx, g->img_exit_open);
	if (g->img_exit_player)
		mlx_destroy_image(g->mlx, g->img_exit_player);
	if (g->mlx && g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	exit(0);
}

void	swap(t_game *g, t_xy now, int y, int x)
{
	char	c;

	if ((g->matrix)[y][x] == '0')
	{
		c = (g->matrix)[now.y][now.x];
		(g->matrix)[now.y][now.x] = (g->matrix)[y][x];
		(g->matrix)[y][x] = c;
		ft_putnbr_fd(++g->n, 1);
		write(1, "\n", 1);
		if (y != g->exit_pos.y || x != g->exit_pos.x)
			g->matrix[g->exit_pos.y][g->exit_pos.x] = 'E';
		render_map(g, &g->matrix, 1);
	}
	else if ((g->matrix)[y][x] == 'C')
	{
		(g->matrix)[y][x] = (g->matrix)[now.y][now.x];
		(g->matrix)[now.y][now.x] = '0';
		ft_putnbr_fd(++g->n, 1);
		write(1, "\n", 1);
		if (y != g->exit_pos.y || x != g->exit_pos.x)
			g->matrix[g->exit_pos.y][g->exit_pos.x] = 'E';
		render_map(g, &g->matrix, 1);
	}
	else if ((g->matrix)[y][x] == 'E')
		swag(g, now, y, x);
}

void	move(int move, t_game *g)
{
	t_xy	p;

	p = pos(g->matrix, 'P');
	if (move == 1)
		if ((g->matrix)[p.y - 1][p.x] != '1')
			swap(g, p, (p.y - 1), p.x);
	if (move == 2)
		if ((g->matrix)[p.y][p.x - 1] != '1')
			swap(g, p, p.y, (p.x - 1));
	if (move == 3)
		if ((g->matrix)[p.y + 1][p.x] != '1')
			swap(g, p, (p.y + 1), p.x);
	if (move == 4)
		if ((g->matrix)[p.y][p.x + 1] != '1')
			swap(g, p, p.y, (p.x + 1));
}

int	key_hook(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
		close_win(g);
	if (keycode == KEY_W || keycode == KEY_UP)
		move(1, g);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move(2, g);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move(3, g);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move(4, g);
	return (0);
}
