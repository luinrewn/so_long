/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 04:42:45 by mprokope          #+#    #+#             */
/*   Updated: 2026/02/10 18:46:32 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include <stdio.h>
#include "so_long.h"

t_xy	pos(char **matrix, char c)
{
	int		x;
	int		y;
	t_xy	pos;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] == c)
				return (pos.x = x, pos.y = y, pos);
			x++;
		}
		y++;
	}
	return (pos.x = 0, pos.y = 0, pos);
}

int	check_1(char **matrix, t_xy pos)
{
	return (matrix[pos.y][pos.x] == '1');
}

void	move_player(char ***matrix, t_xy old_pos, int y, int x)
{
	t_xy	new_pos;
	char	old_char;

	new_pos.x = old_pos.x + x;
	new_pos.y = old_pos.y + y;
	old_char = (*matrix)[new_pos.y][new_pos.x];
	old_pos = pos(*matrix, 'P');
	(*matrix)[old_pos.y][old_pos.x] = '0';
	(*matrix)[new_pos.y][new_pos.x] = 'P';
	if (!check(*matrix) || !check_1((*matrix), new_pos))
	{
		(*matrix)[old_pos.y][old_pos.x] = 'P';
		(*matrix)[new_pos.y][new_pos.x] = old_char;
	}
}

// void	print_pos(t_xy pos)
// {
// 	printf("x:%d y:%d\n", pos.x, pos.y);
// }
