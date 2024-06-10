/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:09:52 by slaye             #+#    #+#             */
/*   Updated: 2024/06/10 15:24:36 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	p_verify(t_program *program)
{
	if (program->argc != 2)
		fexit(program, EX_ARG_FAILURE, ER_ARGS, STDERR_FILENO);
	if (ft_strrchr(program->argv[1], '.') == NULL)
		fexit(program, EX_ARG_FAILURE, ER_ARGS, STDERR_FILENO);
	if (ft_strlen(ft_strrchr(program->argv[1], '.')) != 4)
		fexit(program, EX_ARG_FAILURE, ER_ARGS, STDERR_FILENO);
	if (ft_strncmp(ft_strrchr(program->argv[1], '.'), ".cub", 4) != 0)
		fexit(program, EX_ARG_FAILURE, ER_ARGS, STDERR_FILENO);
}

t_program	*p_setup(int argc, char **argv)
{
	t_program	*program;

	program = ft_calloc(1, sizeof(t_program));
	if (!program)
		fexit(program, EX_FAILURE, ER_MALLOC, STDERR_FILENO);
	program->argc = argc;
	program->argv = argv;
	program->map = NULL;
	return (program);
}

int	main(int argc, char **argv)
{
	t_program	*program;

	program = p_setup(argc, argv);
	p_verify(program);
	parser(program);
	fexit(program, EX_SUCCESS, DB_END, STDIN_FILENO);
}
