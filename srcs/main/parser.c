/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <achoquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:29:00 by achoquel          #+#    #+#             */
/*   Updated: 2019/01/30 09:22:32 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <stdio.h>

int		error(int code)
{
	if (code == 0)
		printf("\033[34m[USAGE] ./fdf {map_path}\033[0m\n");
	else if (code == 1)
		printf("\033[22;31m[ERROR] Map doesn't exists !\033[0m\n");
	else if (code == 2)
		printf("\033[22;31m[ERROR] Lines are not the same length !\033[0m\n");
	else if (code == 3)
		printf("\033[22;31m[ERROR] Use at least a 2x2 map !\033[0m\n");
	else if (code == 4)
		printf("\033[22;31m[ERROR] Error during a malloc process !\033[0m\n");
	else if (code == 5)
		printf("\033[22;31m[ERROR] Map contains invalid characters !\033[0m\n");
	return (1);
}

int		int_counter(char *line)
{
	int	sp;

	sp = 0;
	while (*line != '\0')
	{
		if (*line != ' ' && (*(line + 1) == ' ' || *(line + 1) == '\0'))
			++sp;
		++line;
	}
	return (sp);
}

int		line_checker(char *line, int max, char *map)
{
	int	length;
	int	i;

	length = int_counter(line);
	if (length != max)
	{
		free(map);
		free(line);
		return (error(2));
	}
	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != '-')
		{
			free(map);
			free(line);
			return (error(5));
		}
		++i;
	}
	return (0);
}

void	joiner(char **map, char **line)
{
	char	*tmp;

	tmp = *map;
	*map = ft_strjoin(tmp, *line);
	free(tmp);
	tmp = *map;
	*map = ft_strjoin(tmp, " ");
	ft_strdel(&tmp);
}

int		fdf_parser(t_env *env)
{
	char	*line;
	char	*map;

	env->ymax = 0;
	if (!(map = ft_strnew(0)))
		return (error(4));
	while (get_next_line(env->fd, &line) > 0)
	{
		if (env->ymax == 0)
			env->xmax = int_counter(line);
		if (line_checker(line, env->xmax, map) == 1)
			return (1);
		++env->ymax;
		joiner(&map, &line);
		free(line);
	}
	if (env->xmax < 2 || env->ymax < 2)
		return (error(3));
	env->fmap = ft_strsplit(map, ' ');
	ft_strdel(&map);
	return (0);
}
