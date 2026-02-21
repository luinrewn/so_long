/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 06:23:29 by mprokope          #+#    #+#             */
/*   Updated: 2026/02/10 18:38:37 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	coin_check(char *line)
{
	int	i;

	i = 0;
	while (*line)
	{
		if (*line == 'C')
			i++;
		line++;
	}
	return (i);
}

int	exit_check(char *line)
{
	int	i;

	i = 0;
	while (*line)
	{
		if (*line == 'E')
			i++;
		line++;
	}
	return (i);
}

int	side_char_check(char *li)
{
	while (*li)
	{
		if (*li != 'P' && *li != 'C' && *li != '0' && *li != '1' && *li != 'E')
			return (0);
		li++;
	}
	return (1);
}

int	coll_check(char **matrix)
{
	int	i;
	int	player;
	int	end;
	int	collectible;

	i = 0;
	end = 0;
	player = 0;
	collectible = 0;
	while (matrix[i])
	{
		if (!side_char_check(matrix[i]))
			return (0);
		end += exit_check(matrix[i]);
		collectible += coin_check(matrix[i]);
		player += player_check(matrix[i++]);
	}
	if (player != 1 || end != 1 || collectible < 1)
		return (0);
	return (1);
}

int	check(char **matrix)
{
	if (!rect_check(matrix))
		return (wr("Error\n Map is not rectangular!\n", 2), 0);
	if (rect_check(matrix) == -1)
		return (wr("Error\n Map is too big!\n", 2), 0);
	if (!coll_check(matrix))
		return (wr("Error\n Collectibles are not right!\n", 2), 0);
	if (!border_check(matrix))
		return (wr("Error\n Map have wrong borders!\n", 2), 0);
	if (!check_ava(matrix))
		return (wr("Error\n No valid pathway was found\n", 2), 0);
	return (1);
}
