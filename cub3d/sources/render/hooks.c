/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:10:10 by slaye             #+#    #+#             */
/*   Updated: 2024/06/18 15:38:00 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#define MOVE 0.01


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
	fc_printer(program);
	raycasting(program);
}
