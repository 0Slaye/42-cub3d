/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:04:58 by slaye             #+#    #+#             */
/*   Updated: 2024/06/11 17:34:47 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	check_color(t_program *program, char *color)
{
	char	**split;
	int		i;
	int		counter;

	split = ft_split(color, ',');
	if (!split)
		fexit(program, EX_FAILURE, ER_MAP, STDERR_FILENO);
	counter = -1;
	while (split[++counter])
	{
		i = -1;
		while (split[counter][++i])
		{
			if (!ft_isdigit(split[counter][i]) || ft_strlen(split[counter]) > 3)
			{
				free_split(split);
				fexit(program, EX_FAILURE, ER_MAP, STDERR_FILENO);
			}
		}
	}
	free_split(split);
	if (counter != 3)
		fexit(program, EX_FAILURE, ER_MAP, STDERR_FILENO);
}

void	p_checker(t_program *program)
{
	check_color(program, program->map->f);
	check_color(program, program->map->c);
}
