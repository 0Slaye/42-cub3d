/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:03:39 by slaye             #+#    #+#             */
/*   Updated: 2024/06/12 17:08:30 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	s_window(t_program *program)
{
	mlx_t	*mlx;

	if (!(mlx = mlx_init(W_WIDTH, W_HEIGHT, "MLX42", true)))
		fexit(program, EXIT_FAILURE, ER_MLX, STDERR_FILENO);
	program->mlx = mlx;
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
