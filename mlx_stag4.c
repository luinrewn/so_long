/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stag4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:44:21 by mprokope          #+#    #+#             */
/*   Updated: 2026/02/12 17:28:43 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	swag(t_game *g, t_xy now, int y, int x)
{
	if ((g->matrix)[y][x] == 'E' && !coll_n(g->matrix))
	{
		close_win(g);
		ft_putnbr_fd(++g->n, 1);
		write(1, "\n", 1);
		if (y != g->exit_pos.y || x != g->exit_pos.x)
			g->matrix[g->exit_pos.y][g->exit_pos.x] = 'E';
		render_map(g, &g->matrix, 1);
	}
	else if ((g->matrix)[y][x] == 'E' && coll_n(g->matrix))
	{
		(g->matrix)[y][x] = (g->matrix)[now.y][now.x];
		(g->matrix)[now.y][now.x] = '0';
		ft_putnbr_fd(++g->n, 1);
		write(1, "\n", 1);
		render_map(g, &g->matrix, 0);
	}
}

void	cont_load_img(t_game *g)
{
	g->img_exit_player = mlx_xpm_file_to_image(g->mlx,
			"images/director_on_door.xpm", &g->x, &g->y);
	if (!g->img_exit_player)
		exit((nuke((void **)g->matrix), g->matrix = NULL, close_win(g), -1));
}

void	init_stuff(t_game *g)
{
	g->mlx = NULL;
	g->win = NULL;
	g->img_floor = NULL;
	g->img_wall = NULL;
	g->img_coll = NULL;
	g->img_player = NULL;
	g->img_exit = NULL;
	g->img_exit_open = NULL;
	g->img_exit_player = NULL;
}
