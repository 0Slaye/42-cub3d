/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:10:10 by slaye             #+#    #+#             */
/*   Updated: 2024/06/12 17:25:32 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	hooks(void *program)
{
	mlx_t	*mlx = (mlx_t *) (((t_program *) program)->mlx);

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
		fexit(program, EXIT_SUCCESS, DB_END, STDIN_FILENO);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		printf("key: Q\n");
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		printf("key: Z\n");
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		printf("key: D\n");
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		printf("key: S\n");
}
