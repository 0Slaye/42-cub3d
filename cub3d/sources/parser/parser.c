/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:41:44 by slaye             #+#    #+#             */
/*   Updated: 2024/06/10 16:29:41 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "get_next_line.h"

void	get_file(t_program *program, int fd)
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


void	parser(t_program *program)
{
	int		fd;

	fd = open(program->argv[1], O_RDONLY);
	if (fd == -1)
		fexit(program, EX_FAILURE, ER_OPEN, STDERR_FILENO);
	get_file(program, fd);
	close(fd);
}
