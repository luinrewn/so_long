/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:39:05 by mprokope          #+#    #+#             */
/*   Updated: 2026/02/12 17:34:43 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "so_long.h"
#include <stdio.h>

// void	print_list(char **matrix)
// {
// 	int	i;

// 	i = 0;
// 	while (matrix[i])
// 		printf("%s\n", matrix[i++]);
// }

int	create_init_grid(char **argv, char ***matrix)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	if (fd < 0)
		return (close(fd), 0);
	*matrix = malloc(sizeof(char *) * (count(argv) + 1));
	if (!(*matrix))
		exit (-1);
	line = get_next_line(fd);
	if (!line)
		return (free(*matrix), close(fd), 0);
	while (line)
	{
		(*matrix)[i++] = line;
		line = get_next_line(fd);
	}
	(*matrix)[i] = NULL;
	strip_nw(matrix);
	close(fd);
	return (1);
}

t_xy	count_smth(char **matrix)
{
	t_xy	i;

	i.x = 0;
	while (matrix[i.x])
	{
		i.y = 0;
		while (matrix[i.x][i.y])
			i.y++;
		i.x++;
	}
	return (i);
}

void	*render_walls(t_game g, char ***matrix)
{
	void	*img;
	int		xx;
	int		yy;
	int		i;
	int		j;

	img = g.img_wall;
	yy = 0;
	i = 0;
	while (yy + g.y < WIN_H && (*matrix)[i])
	{
		xx = 0;
		j = 0;
		while (xx + g.x < WIN_W && (*matrix)[i][j])
		{
			if ((*matrix)[i][j] && (*matrix)[i][j] == '1')
				mlx_put_image_to_window(g.mlx, g.win, img, xx, yy);
			xx += g.x;
			j++;
		}
		yy += g.y;
		i++;
	}
	return (img);
}

int	main(int argc, char **argv)
{
	t_game	g;
	t_xy	s;

	if (argc == 2 && check_ext(argv[1]))
	{
		if (!create_init_grid(argv, &g.matrix))
			exit (wr("Error\n Empty Map\n", 2));
		if (!check(g.matrix) && g.matrix)
			exit((nuke((void **)g.matrix), g.matrix = NULL, -1));
		s = count_smth(g.matrix);
		init_stuff(&g);
		g.mlx = mlx_init();
		g.exit_pos = pos(g.matrix, 'E');
		if (!g.mlx)
			exit((nuke((void **)g.matrix), g.matrix = NULL, -1));
		g.n = 0;
		load_img(&g);
		g.win = mlx_new_window(g.mlx, win_size(s.y, 32), win_size(s.x, 46),
				"so_long");
		render_map(&g, &g.matrix, 1);
		mlx_hook(g.win, 2, 1L << 0, key_hook, &g);
		mlx_hook(g.win, 17, 1L << 0, close_win, &g);
		mlx_loop(g.mlx);
	}
	wr("Error\n Usage: ./so_long map.ber\n", 2);
}
//		mlx_string_put(mlx, mlx_w, WIN_W / 2, WIN_H / 2, 0424242, "Testing");i
// if (!astar(matrix, coll_n(matrix), 'C')) printf("NOPE\n");
// mlx_key_hook(g.win, key_hook, &g);
// mlx_key_hook(g.win, key_hook, &g);
// int	main(int argc, char **argv)
// {
// 	//int		fd;
// 	char	**matrix;
// 	//int		i;
// 	//char	c;
// 	// char	*line;

// 	if (argc == 2 && check_ext(argv[1]))
// 	{
// //------------------Grab-ToMatrix--------------------
// 		// fd = open(argv[1], O_RDONLY);
// 		// i = 0;
// 		// if (fd < 0)
// 		// 	return (0);
// 		// matrix = malloc(sizeof(char *) * (count(argv) + 1));
// 		// if (!matrix)
// 		// 	return (0);
// 		// while ((line = get_next_line(fd)))
// 		// 	matrix[i++] = line;
// 		// free(line);
// 		// matrix[i] = NULL;
// 		//strip_nw(&matrix);
// 		if (!create_init_grid(argv, &matrix))
// 			return (0);
// //-------------End--Grab-ToMatrix--------------------
// 		if (!check(matrix))
// 		{
// 			//nuke((void **)matrix);
// 			matrix = NULL;
// 			//close(fd);
// 			exit(1);
// 		}
// 		print_pos(pos(matrix, 'P'));
// 		print_list(matrix);
// 		printf("\n");
// 		move_player(&matrix, pos(matrix, 'P'), -1, 1);
// 		print_pos(pos(matrix, 'P'));
// 		if (check(matrix))
// 			print_list(matrix);
// 		else
// 			printf("Error\n");
// 		// int	astar(char **matrix, int coll_n, char symbl)
// 		if (!astar(matrix, coll_n(matrix), 'C')) printf("NOPE\n");
// 		// i = 0;
// 		//nuke((void **)matrix);
// 		matrix = NULL;
// 		//close(fd);
// 	}
// 	else
// 		wr("Wrong data number of argument or extension!\n", 2);
// }
/*int	main(int argc, char **argv)
{
	int		fd;
	char	**matrix;
	int		i;
	char	*line;
	char	c;

	if (argc == 2)
	{
//------------------Grab-ToMatrix--------------------
		fd = open(argv[1], O_RDONLY);
		i = 0;
		if (fd < 0)
			return (0);
		matrix = malloc(sizeof(char *) * (count(argv) + 1));
		if (!matrix)
			return (0);
		while ((line = get_next_line(fd)))
			matrix[i++] = line;
		free(line);
		matrix[i] = NULL;
		strip_nw(&matrix);
//-------------End--Grab-ToMatrix--------------------
		if (check(matrix))
			print_list(matrix);
		else
			printf("Error\n");
		i = 0;
		while (matrix[i])
			free(matrix[i++]);
		free(matrix);
		close(fd);
	}
}
*/
