/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 06:47:42 by mprokope          #+#    #+#             */
/*   Updated: 2026/02/05 20:50:52 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// typedef struct t_array
// {
//     int g;
//     int h;
//     int f;
//     int closed;
// } t_array;
#include "so_long.h"

t_xy	find_and_skip(char **matrix, char c, int skip)
{
	int			y;
	int			x;
	t_xy		cords;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] == c)
			{
				if (skip)
					skip--;
				else
					return (cords.x = x, cords.y = y, cords);
			}
			x++;
		}
		y++;
	}
	return (cords.x = 0, cords.y = 0, cords);
}

int	h_of(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	init_vars(t_array *array, char **matrix, int x, int y)
{
	int	i;

	i = 0;
	while (i < x)
	{
		array[i].g = INT_MAX;
		array[i].h = 0;
		array[i].f = INT_MAX;
		array[i].closed = 0;
		if (matrix[y][i] == '1')
			array[i].closed = 1;
		i++;
	}
}

t_array	**init_arr(char **matrix)
{
	t_array	**array;
	int		y;
	int		x;
	int		h;

	h = h_of(matrix);
	array = malloc(sizeof(t_array *) * (h + 1));
	if (!array)
		return (NULL);
	array[h] = NULL;
	x = ft_strlen(*matrix);
	y = 0;
	while (y < h)
	{
		array[y] = malloc(sizeof(t_array) * x);
		if (!array[y])
			return (nuke((void **)array), array = NULL, NULL);
		init_vars(array[y], matrix, x, y);
		y++;
	}
	return (array);
}

int	check_ava(char **matrix)
{
	int	coll;

	coll = coll_n(matrix);
	if (astar(matrix, 0, 'P') == 0)
		return (0);
	while (coll--)
	{
		if (astar(matrix, coll, 'C') == 0)
			return (0);
	}
	return (1);
}
