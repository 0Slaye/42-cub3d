/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:44:13 by slaye             #+#    #+#             */
/*   Updated: 2024/06/10 17:41:29 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

char	*get_line_value(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	return (&line[i]);
}

void	set_map_vars_loop(t_program *program, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 && program->map->no != NULL)
		fexit(program, EX_FAILURE, ER_MAP, STDERR_FILENO);
	else if (ft_strncmp(line, "NO ", 3) == 0 && program->map->no == NULL)
		program->map->no = ft_strdup(get_line_value(&line[2]));
	if (ft_strncmp(line, "SO ", 3) == 0 && program->map->so != NULL)
		fexit(program, EX_FAILURE, ER_MAP, STDERR_FILENO);
	else if (ft_strncmp(line, "SO ", 3) == 0 && program->map->so == NULL)
		program->map->so = ft_strdup(get_line_value(&line[2]));
	if (ft_strncmp(line, "WE ", 3) == 0 && program->map->we != NULL)
		fexit(program, EX_FAILURE, ER_MAP, STDERR_FILENO);
	else if (ft_strncmp(line, "WE ", 3) == 0 && program->map->we == NULL)
		program->map->we = ft_strdup(get_line_value(&line[2]));
	if (ft_strncmp(line, "EA ", 3) == 0 && program->map->ea != NULL)
		fexit(program, EX_FAILURE, ER_MAP, STDERR_FILENO);
	else if (ft_strncmp(line, "EA ", 3) == 0 && program->map->ea == NULL)
		program->map->ea = ft_strdup(get_line_value(&line[2]));
	if (ft_strncmp(line, "F ", 2) == 0 && program->map->f != NULL)
		fexit(program, EX_FAILURE, ER_MAP, STDERR_FILENO);
	else if (ft_strncmp(line, "F ", 2) == 0 && program->map->f == NULL)
		program->map->f = ft_strdup(get_line_value(&line[1]));
	if (ft_strncmp(line, "C ", 2) == 0 && program->map->c != NULL)
		fexit(program, EX_FAILURE, ER_MAP, STDERR_FILENO);
	else if (ft_strncmp(line, "C ", 2) == 0 && program->map->c == NULL)
		program->map->c = ft_strdup(get_line_value(&line[1]));
}

int	set_map_grid_loop(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}