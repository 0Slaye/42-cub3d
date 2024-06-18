/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:03:39 by slaye             #+#    #+#             */
/*   Updated: 2024/06/18 19:17:25 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

// TODO: check for textures and load them
void	s_window(t_program *program)
{
	mlx_t		*mlx;
	mlx_image_t	*screen;
	mlx_image_t	*minimap;

	mlx = mlx_init(W_WIDTH, W_HEIGHT, "cub3D", true);
	if (!mlx)
		fexit(program, EXIT_FAILURE, ER_MLX, STDERR_FILENO);
	screen = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
	minimap = mlx_new_image(mlx, W_WIDTH / 4, W_HEIGHT / 4);
	if (!screen || !minimap)
		fexit(program, EXIT_FAILURE, ER_MLX, STDERR_FILENO);
	if (mlx_image_to_window(mlx, screen, 0, 0) == -1)
		fexit(program, EXIT_FAILURE, ER_MLX, STDERR_FILENO);
	if (mlx_image_to_window(mlx, minimap, 0, 0) == -1)
		fexit(program, EXIT_FAILURE, ER_MLX, STDERR_FILENO);
	program->mlx = mlx;
	program->screen = screen;
	program->minimap = minimap;
	mlx_loop_hook(program->mlx, hooks, program);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
