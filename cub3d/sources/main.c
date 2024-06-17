/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:09:52 by slaye             #+#    #+#             */
/*   Updated: 2024/06/17 14:57:17 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	p_verify(t_program *program)
{
	if (program->argc != 2)
		fexit(program, EXIT_FAILURE, ER_ARGS, STDERR_FILENO);
	if (ft_strrchr(program->argv[1], '.') == NULL)
		fexit(program, EXIT_FAILURE, ER_ARGS, STDERR_FILENO);
	if (ft_strlen(ft_strrchr(program->argv[1], '.')) != 4)
		fexit(program, EXIT_FAILURE, ER_ARGS, STDERR_FILENO);
	if (ft_strncmp(ft_strrchr(program->argv[1], '.'), ".cub", 4) != 0)
		fexit(program, EXIT_FAILURE, ER_ARGS, STDERR_FILENO);
}

t_program	*p_setup(int argc, char **argv)
{
	t_program	*program;

	program = ft_calloc(1, sizeof(t_program));
	if (!program)
		fexit(program, EXIT_FAILURE, ER_MALLOC, STDERR_FILENO);
	program->argc = argc;
	program->argv = argv;
	program->map = NULL;
	program->fd = -1;
	program->player = NULL;
	return (program);
}

t_map	*m_setup(t_program *program)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		fexit(program, EXIT_FAILURE, ER_MALLOC, STDERR_FILENO);
	map->file = NULL;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f = NULL;
	map->c = NULL;
	map->lst_grid = NULL;
	map->grid = NULL;
	return (map);
}

int	main(int argc, char **argv)
{
	t_program	*program;

	program = p_setup(argc, argv);
	program->map = m_setup(program);
	p_verify(program);
	parser(program);
	program->player = s_player(program);
	//printf("Player position: (%f,%f)\n", program->player->x, program->player->y);
	//printf("Player facing: (%c)\n", program->player->spawn);
	s_window(program);
	fexit(program, EXIT_SUCCESS, DB_END, STDIN_FILENO);
}
