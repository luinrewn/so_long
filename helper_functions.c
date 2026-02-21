/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:45:38 by mprokope          #+#    #+#             */
/*   Updated: 2026/02/11 00:20:17 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *line)
{
	char	*s;

	s = line;
	while (*s)
		s++;
	return ((int)(s - line));
}

int	wr(char *str, int fd)
{
	if (write(fd, str, ft_strlen(str)) == -1)
		exit(-1);
	return (0);
}

void	strip_nw(char ***matrix)
{
	int	i;
	int	j;

	i = 0;
	while ((*matrix)[i])
	{
		j = ft_strlen((*matrix)[i]);
		while (j > 0 && ((*matrix)[i][j - 1] == '\n' || (*matrix)[i][j
				- 1] == '\r'))
		{
			(*matrix)[i][--j] = '\0';
		}
		i++;
	}
}

int	count(char **argv)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (close(fd), -1);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	check_ext(char *line)
{
	int		len;
	char	*str;

	if (!line || !line[0])
		exit(-1);
	str = ".ber";
	len = (ft_strlen(line) - 4);
	while (line[len])
	{
		if (line[len] != *str++)
			return (0);
		len++;
	}
	return (1);
}
