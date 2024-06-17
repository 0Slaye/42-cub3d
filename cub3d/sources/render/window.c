/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:03:39 by slaye             #+#    #+#             */
/*   Updated: 2024/06/17 19:46:39 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

// TODO: check for textures and load them
void	s_window(t_program *program)
{
	mlx_t		*mlx;
	mlx_image_t	*screen;

	mlx = mlx_init(W_WIDTH, W_HEIGHT, "cub3D", true);
	if (!mlx)
		fexit(program, EXIT_FAILURE, ER_MLX, STDERR_FILENO);
	screen = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
	if (!screen)
		fexit(program, EXIT_FAILURE, ER_MLX, STDERR_FILENO);
	if (mlx_image_to_window(mlx, screen, 0, 0) == -1)
		fexit(program, EXIT_FAILURE, ER_MLX, STDERR_FILENO);
	program->mlx = mlx;
	program->screen = screen;
	mlx_loop_hook(program->mlx, hooks, program);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
