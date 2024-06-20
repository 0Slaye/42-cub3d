/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:48:40 by slaye             #+#    #+#             */
/*   Updated: 2024/06/20 15:30:09 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	player_init(t_program *p)
{
	if (p->player_img)
		mlx_delete_image(p->mlx, p->player_img);
	p->player_img = mlx_new_image(p->mlx, W_WIDTH / 2, W_HEIGHT);
	if (mlx_image_to_window(p->mlx, p->player_img, 0, 0) == -1)
		fexit(p, EXIT_FAILURE, ER_MLX, STDERR_FILENO);
}

void	draw_player(t_program *p)
{
	int	x;
	int	y;

	player_init(p);
	y = p->player->y * SQUARE * p->map->ratio_y;
	while (y < p->player->y * SQUARE * p->map->ratio_y + SQUARE / 2 * p->map->ratio_y)
	{
		x = p->player->x * SQUARE * p->map->ratio_x;
		while (x < p->player->x * SQUARE * p->map->ratio_x + SQUARE / 2 * p->map->ratio_y)
		{
			mlx_put_pixel(p->player_img, x, y, 0xBFF23DFF);
			x++;
		}
		y++;
	}
	mlx_put_pixel(p->player_img, p->player->x, p->player->y, 0xBFF23DFF);
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
