/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:04:58 by slaye             #+#    #+#             */
/*   Updated: 2024/06/11 17:58:17 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

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

void	check_grid(t_program *program, t_list *grid)
{
	t_list	*holder;
	char	c;
	int		i;

	holder = grid;
	while (holder)
	{
		i = -1;
		while (((char *) holder->content)[++i] != '\0')
		{
			c = ((char *) holder->content)[i];
			if (c != EMPTY && c != WALL && c != NORD && c != SOUTH && c != EST && c != WEST && c != ' ')
				fexit(program, EX_FAILURE, ER_MAP, STDERR_FILENO);
		}
		holder = holder->next;
	}
}

void	map_checker(t_program *program)
{
	check_color(program, program->map->f);
	check_color(program, program->map->c);
	check_grid(program, program->map->grid);
}
