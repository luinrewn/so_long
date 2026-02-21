/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprokope <mprokope@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 06:10:37 by mprokope          #+#    #+#             */
/*   Updated: 2026/02/10 18:37:55 by mprokope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	one(char c)
{
	return (c == '1');
}

int	rect_check(char **matrix)
{
	int	len;
	int	i;

	i = 1;
	len = ft_strlen(matrix[0]);
	if (len > 59)
		return (-1);
	while (matrix[i])
	{
		if (len != ft_strlen(matrix[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_line(char *line)
{
	int	i;
	int	len;

	len = ft_strlen(line);
	i = 0;
	while (i < len)
		if (line[i++] != '1')
			return (0);
	return (1);
}

int	check_middle(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (i == 0 && !one(line[i]))
			return (0);
		if (!line[i + 1] && !one(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	border_check(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (i == 0 && !check_line(matrix[i]))
			return (0);
		if (!matrix[i + 1] && !check_line(matrix[i]))
			return (0);
		if (!check_middle(matrix[i++]))
			return (0);
		if (i > 22)
			return (0);
	}
	return (1);
}
