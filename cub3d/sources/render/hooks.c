/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:10:10 by slaye             #+#    #+#             */
/*   Updated: 2024/06/18 16:03:57 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#define MOVE 0.01

void	clear_image(t_program *program)
{
	int	y;
	int	x;

	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			mlx_put_pixel(program->screen, y, x, 0xFF);
			x++;
		}
		y++;
	}
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
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		p->player->y -= MOVE;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		p->player->x -= MOVE;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		p->player->x += MOVE;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		p->player->y += MOVE;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		p->player->rotation += 0.01;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		p->player->rotation -= 0.01;
	clear_image(program);
	raycasting(program);
}
