/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:31:52 by mde-lang          #+#    #+#             */
/*   Updated: 2024/06/18 16:44:07 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	fc_printer(t_program *program)
{
	char	**ceiling;
	char	**floor;
	int		y;
	int		x;

	y = 0;
	ceiling = ft_split(program->map->c, ',');
	floor = ft_split(program->map->f, ',');
	if (!ceiling || !floor)
		fexit(program, EXIT_FAILURE, ER_MALLOC, STDERR_FILENO);
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x++ < W_WIDTH / 2)
			mlx_put_pixel(program->screen, y, x, ft_pixel(ft_atoi(ceiling[0]), ft_atoi(ceiling[1]), ft_atoi(ceiling[2]), 255));
		while (x++ < W_WIDTH)
			mlx_put_pixel(program->screen, y, x, ft_pixel(ft_atoi(floor[0]), ft_atoi(floor[1]), ft_atoi(floor[2]), 255));
		y++;
	}
	free_split(ceiling);
	free_split(floor);
}
