/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_staff3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 06:10:52 by mprokope          #+#    #+#             */
/*   Updated: 2026/02/09 20:42:42 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_size(int x, int num)
{
	return (x * num);
}

void	nuke(void **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

int	player_check(char *line)
{
	int	i;

	i = 0;
	while (*line)
	{
		if (*line == 'P')
			i++;
		line++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	temp;

	if (fd < 0)
		return ;
	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	temp = (n % 10) + '0';
	write(fd, &temp, 1);
}

void	insanity(int fuck[8])
{
	fuck[0] = 1;
	fuck[1] = -1;
	fuck[2] = 0;
	fuck[3] = 0;
	fuck[4] = 0;
	fuck[5] = 0;
	fuck[6] = 1;
	fuck[7] = -1;
}
//not mlx stuff
