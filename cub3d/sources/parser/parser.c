/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:41:44 by slaye             #+#    #+#             */
/*   Updated: 2024/06/10 17:47:16 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "get_next_line.h"

void	get_map_file(t_program *program, int fd)
{
	t_list	*holder;
	char	*value;

	value = get_next_line(fd);
	while (value)
	{
		holder = ft_lstnew(value);
		if (!holder)
		{
			free(value);
			close(fd);
			fexit(program, EX_FAILURE, ER_OPEN, STDERR_FILENO);
		}
		ft_lstadd_back(&program->map->file, holder);
		value = get_next_line(fd);
	}
}

void	set_map_vars(t_program *program)
{
	t_list	*holder;

	holder = program->map->file;
	while (holder)
	{
		set_map_vars_loop(program, holder->content);
		holder = holder->next;
	}
}

void	check_map_vars(t_program *program)
{
	t_map	*map;

	map = program->map;
	if (!map->no || !map->so || !map->we || !map->ea || !map->f || !map->c)
		fexit(program, EX_FAILURE, ER_MAP, STDERR_FILENO);
}

void	set_map_grid(t_program *program)
{
	t_list	*holder;
	int		i;

	holder = program->map->file;
	i = 0;
	while (holder)
	{
		if (i < 4)
			i += set_map_grid_loop(holder->content);
		else
			// TODO: choose between t_list or char ** and add map value
		holder = holder->next;
	}
}

void	parser(t_program *program)
{
	int		fd;

	fd = open(program->argv[1], O_RDONLY);
	if (fd == -1)
		fexit(program, EX_FAILURE, ER_OPEN, STDERR_FILENO);
	get_map_file(program, fd);
	set_map_vars(program);
	check_map_vars(program);
	set_map_grid(program);
	close(fd);
}
