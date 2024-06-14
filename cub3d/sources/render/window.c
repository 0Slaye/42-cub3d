/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:03:39 by slaye             #+#    #+#             */
/*   Updated: 2024/06/14 17:21:19 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#define RAYS 10.0
#define ANGLE 80.0
#define SCELL 64.0

void	raycasting(t_program *program)
{
	double	angle;
	//int		Ay;
	//int		Ax;

	angle = ANGLE / RAYS;
	while (angle < ANGLE)
	{
		printf("%f\n", floor(program->player->y / 64.0f));
		angle += ANGLE / RAYS;
	}
}

void	s_window(t_program *program)
{
	mlx_t	*mlx; // TODO: check for textures and load them

	raycasting(program);
	if (!(mlx = mlx_init(W_WIDTH, W_HEIGHT, "cub3D", true)))
		fexit(program, EXIT_FAILURE, ER_MLX, STDERR_FILENO);
	program->mlx = mlx;
	mlx_loop_hook(program->mlx, hooks, program);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

