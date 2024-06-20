/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:48:40 by slaye             #+#    #+#             */
/*   Updated: 2024/06/20 13:33:54 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	m_player(t_player *player, int y, int x, char c)
{
	player->y = y + 0.5;
	player->x = x + 0.5;
	if (c == NORTH)
		player->rotation = PI / 2;
	else if (c == SOUTH)
		player->rotation = 3 * PI / 2;
	else if (c == WEST)
		player->rotation = PI;
	else if (c == EST)
		player->rotation = 0;
}

t_player	*s_player(t_program *program)
{
	t_player	*player;
	int			y;
	int			x;
	char		c;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		fexit(program, EXIT_FAILURE, ER_MALLOC, STDERR_FILENO);
	y = -1;
	while (program->map->grid[++y])
	{
		x = -1;
		while (program->map->grid[y][++x])
		{
			c = program->map->grid[y][x];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
				return (m_player(player, y, x, c), player);
		}
	}
	return (player);
}
