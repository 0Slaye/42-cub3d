/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:10:10 by slaye             #+#    #+#             */
/*   Updated: 2024/06/22 16:55:28 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

bool	check_collision(t_program *p, double prediction_y, double prediction_x)
{
	int	map_y;
	int	map_x;

	map_y = (int)floor(prediction_y);
	map_x = (int)floor(prediction_x);
	if (p->map->grid[map_y][map_x] == WALL)
		return (true);
	return (false);
}

void	move(t_program *p, double angle)
{
	double	new_y;
	double	new_x;

	new_y = p->player->y + MOVE * cos(p->player->rotation - angle);
	new_x = p->player->x + MOVE * sin(p->player->rotation - angle);
	if (!check_collision(p, new_y, new_x))
	{
		p->player->y = new_y;
		p->player->x = new_x;
	}
}

void	look(t_player *player, int value)
{
	player->rotation += ROT * value;
	if (value == 1 && player->rotation > 2 * PI)
		player->rotation -= 2 * PI;
	else if (value == -1 && player->rotation < 0)
		player->rotation += 2 * PI;
}

void	is_key_down(t_program *p)
{
	if (mlx_is_key_down(p->mlx, MLX_KEY_W) && (check_collision(p, p->player->y - MOVE, p->player->x) == false))
		p->player->y -= MOVE;
	if (mlx_is_key_down(p->mlx, MLX_KEY_A) && (check_collision(p, p->player->y, p->player->x - MOVE) == false))
		p->player->x -= MOVE;
	if (mlx_is_key_down(p->mlx, MLX_KEY_D) && (check_collision(p, p->player->y, p->player->x + MOVE) == false))
		p->player->x += MOVE;
	if (mlx_is_key_down(p->mlx, MLX_KEY_S) && (check_collision(p, p->player->y + MOVE, p->player->x) == false))
		p->player->y += MOVE;
	if (mlx_is_key_down(p->mlx, MLX_KEY_LEFT))
		look(p->player, 1);
	if (mlx_is_key_down(p->mlx, MLX_KEY_RIGHT))
		look(p->player, -1);
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
	is_key_down(program);
	fc_printer(program);
	raycasting(program);
	draw_map(program);
	draw_player(program);
}
