/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:48:40 by slaye             #+#    #+#             */
/*   Updated: 2024/06/14 15:05:41 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

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
			{
				player->spawn = c;
				player->y = y + 0.5;
				player->x = x + 0.5;
				return (player);
			}
		}
	}
	return (player);
}
