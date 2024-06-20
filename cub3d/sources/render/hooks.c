/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:10:10 by slaye             #+#    #+#             */
/*   Updated: 2024/06/20 03:59:04 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

bool	check_collision(t_program *p, double prediction_y, double prediction_x)
{
	if (p->map->grid[(int)floor(prediction_y)][(int)floor(prediction_x)] == WALL)
		return (true);
	return (false);
}

void	hooks(void *program)
{
	t_program	*p;
	mlx_t		*mlx;

	p = (t_program *) program;
	mlx = p->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
		fexit(program, EXIT_SUCCESS, DB_END, STDIN_FILENO);
	}
	if (mlx_is_key_down(p->mlx, MLX_KEY_W) && (check_collision(p, p->player->y - MOVE, p->player->x) == false))
		p->player->y -= MOVE;
	if (mlx_is_key_down(p->mlx, MLX_KEY_A) && (check_collision(p, p->player->y, p->player->x - MOVE) == false))
		p->player->x -= MOVE;
	if (mlx_is_key_down(p->mlx, MLX_KEY_D) && (check_collision(p, p->player->y, p->player->x + MOVE) == false))
		p->player->x += MOVE;
	if (mlx_is_key_down(p->mlx, MLX_KEY_S) && (check_collision(p, p->player->y + MOVE, p->player->x) == false))
		p->player->y += MOVE;
	if (mlx_is_key_down(p->mlx, MLX_KEY_LEFT))
		p->player->rotation += MOVE;
	if (mlx_is_key_down(p->mlx, MLX_KEY_RIGHT))
		p->player->rotation -= MOVE;
	fc_printer(program);
	raycasting(program);
	draw_map(program);
	draw_player(program);
}
