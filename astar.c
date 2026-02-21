/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 06:47:42 by mprokope          #+#    #+#             */
/*   Updated: 2026/02/12 17:33:13 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int	manhattan(t_xy first, t_xy second)
{
	return ((int)(fabs((float)first.x - (float)second.x)
		+ fabs((float)first.y - (float)second.y)));
}

int	lowest_f(t_array **ar, char **ma, t_xy *cord)
{
	int	x;
	int	y;
	int	best;
	int	found;

	best = INT_MAX;
	y = 0;
	found = 0;
	while (ma[y])
	{
		x = 0;
		while (ma[y][x])
		{
			if (!ar[y][x].closed && ar[y][x].g < INT_MAX && ar[y][x].f < best)
			{
				best = ar[y][x].f;
				cord->x = x;
				cord->y = y;
				found = 1;
			}
			x++;
		}
		y++;
	}
	return (found);
}

int	coll_n(char **matrix)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] == 'C')
				i++;
			x++;
		}
		y++;
	}
	return (i);
}

void	astar_helper(t_array ***array, char **matrix, t_xy cur, int cords[])
{
	int		x;
	int		y;
	int		i;
	t_xy	end;

	end = find_and_skip(matrix, 'E', 0);
	i = 0;
	while (i < 4)
	{
		x = cur.x + cords[i];
		y = cur.y + cords[i + 4];
		if (x < 0 || y < 0 || !matrix[y] || !matrix[y][x]
			|| matrix[y][x] == '1' || (*array)[y][x].closed)
		{
			i++;
			continue ;
		}
		if ((*array)[cur.y][cur.x].g + 1 < (*array)[y][x].g)
		{
			(*array)[y][x].g = (*array)[cur.y][cur.x].g + 1;
			(*array)[y][x].h = manhattan((t_xy){x, y}, end);
			(*array)[y][x].f = (*array)[y][x].g + (*array)[y][x].h;
		}
		i++;
	}
}

int	astar(char **matrix, int coll_n, char symbl)
{
	t_array	**array;
	t_xy	start;
	t_xy	end;
	t_xy	cur;
	int		ar[8];

	start = find_and_skip(matrix, symbl, coll_n);
	end = find_and_skip(matrix, 'E', 0);
	array = init_arr(matrix);
	if (!array)
		return (-1);
	array[start.y][start.x].g = 0;
	array[start.y][start.x].h = manhattan(start, end);
	array[start.y][start.x].f = array[start.y][start.x].h;
	while (lowest_f(array, matrix, &cur))
	{
		if (cur.x == end.x && cur.y == end.y)
			return (nuke((void **)array), 1);
		array[cur.y][cur.x].closed = 1;
		insanity(ar);
		astar_helper(&array, matrix, cur, ar);
	}
	return (nuke((void **)array), array = NULL, 0);
}

//return (0); - see if it works
/*
int	algo(char **matrix, t_xy start, t_xy end, int h)
{
	t_xy	begnining;

	begnining = start;
	while (start != end)
	{
		if (matrix[start.y][start.y] != '1')
		{
			//TODO
		}
	}
}
*/
// char	**man_matrix(char **matrix)
// {
// 	return (matrix);
// }

// int	create_init_grid(char **argv, char ***matrix)
// {
// 	int		fd;
// 	int		i;
// 	char	*line;

// 	fd = open(argv[1], O_RDONLY);
// 	i = 0;
// 	if (fd < 0)
// 		return (close(fd), 0);
// 	*matrix = malloc(sizeof(char *) * (count(argv) + 1));
// 	if (!(*matrix))
// 		return (0);
// 	while ((line = get_next_line(fd)))
// 		(*matrix)[i++] = line;
// 	(*matrix)[i] = NULL;
// 	strip_nw(matrix);
// 	close(fd);
// 	return (1);
// }

// int **build_man_grid(char **matrix)
// {
// 	int	**man_grid;
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (matrix[y])
// 		y++;
// 	man_grid = malloc(sizeof(int *) * (y + 1));
// 	if (!man_grid)
// 		return (NULL);
// 	man_grid[y + 1] = NULL;
// 	y = 0;
// 	while (matrix[y])
// 	{
// 		man_grid[y] = malloc(sizeof(int) * ft_strlen(matrix[y]));
// 		if (!man_grid[y])
// 			return (NULL);
// 		x = 0;
// 		while (matrix[y][x])
// 		{
// 			man_grid[y][x] = 
//Manhattan((t_xy){x, y}, find_and_skip(matrix, 'E', 0));
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (man_grid);
// }

// int	astar(char **matrix)
// {
// 	return (printf("%d\n", Manhattan(find_and_skip(matrix, 'C', 4), 
//find_and_skip(matrix, 'E', 0))));
// }
