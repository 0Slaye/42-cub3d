/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:44:59 by slaye             #+#    #+#             */
/*   Updated: 2024/06/19 16:00:22 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

int	is_in_map(char **grid, int y, int x)
{
	int	i;

	i = 0;
	while (grid[i])
		i++;
	if (y < 0 || y >= i)
		return (0);
	else if (x < 0 || x >= (int) ft_strlen(grid[y]))
		return (0);
	return (1);
}

void	draw_line(t_program *program, int step, double distance)
{
	int	i;
	int	length;
	int	holder;

	length = W_HEIGHT / distance;
	if (length > W_HEIGHT)
		length = W_HEIGHT;
	i = (W_HEIGHT / 2) - (length / 2);
	holder = i + length;
	while (i < holder)
		mlx_put_pixel(program->screen, step, i++, 0xFFFFFFFF);
}

void	raycasting(t_program *program)
{
	double	i;
	int		rays;
	double	step;
	double	horizontal;
	double	vertical;
	double	holder;
	
	if (!program->player->rotation)
		program->player->rotation = PI / 2;
	i = 0;
	rays = W_WIDTH / 2;
	step = PI / 2 / rays;
	holder = program->player->rotation - PI / 4;
	while (i < rays)
	{
		program->player->rayrot = holder;
		horizontal = get_horizontal(program);
		vertical = get_vertical(program);
		if (horizontal < vertical)
			draw_line(program, W_WIDTH - i, horizontal);
		else
			draw_line(program, W_WIDTH - i, vertical);
		i++;
		holder += step;
	}
}
