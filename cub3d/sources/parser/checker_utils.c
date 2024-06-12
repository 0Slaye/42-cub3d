/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:53:21 by slaye             #+#    #+#             */
/*   Updated: 2024/06/12 17:13:13 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

int	selected_cell_check(char value)
{
	if (value == EMPTY || value == NORD || value == SOUTH)
		return (1);
	if (value == EST || value == WEST)
		return (1);
	return (0);
}

int	cell_if_check(char value)
{
	if (value != WALL && value != EMPTY)
	{
		if (value != NORD && value != SOUTH && value != EST && value != WEST)
			return (0);
	}
	return (1);
}

void	check_cell_border(t_program *program, char **grid, int y, int x)
{
	int	y_size;

	y_size = ft_lstsize(program->map->lst_grid);
	if (selected_cell_check(grid[y][x]))
	{
		if (y == 0 || y == y_size || x == 0 || x == (int) ft_strlen(grid[y]))
			fexit(program, EXIT_FAILURE, ER_MAP, STDERR_FILENO);
		if (!cell_if_check(grid[y - 1][x]))
			fexit(program, EXIT_FAILURE, ER_MAP, STDERR_FILENO);
		if (!cell_if_check(grid[y - 1][x + 1]))
			fexit(program, EXIT_FAILURE, ER_MAP, STDERR_FILENO);
		if (!cell_if_check(grid[y][x + 1]))
			fexit(program, EXIT_FAILURE, ER_MAP, STDERR_FILENO);
		if (!cell_if_check(grid[y + 1][x + 1]))
			fexit(program, EXIT_FAILURE, ER_MAP, STDERR_FILENO);
		if (!cell_if_check(grid[y + 1][x]))
			fexit(program, EXIT_FAILURE, ER_MAP, STDERR_FILENO);
		if (!cell_if_check(grid[y + 1][x - 1]))
			fexit(program, EXIT_FAILURE, ER_MAP, STDERR_FILENO);
		if (!cell_if_check(grid[y][x - 1]))
			fexit(program, EXIT_FAILURE, ER_MAP, STDERR_FILENO);
		if (!cell_if_check(grid[y - 1][x - 1]))
			fexit(program, EXIT_FAILURE, ER_MAP, STDERR_FILENO);
	}
}
