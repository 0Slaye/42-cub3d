/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:44:59 by slaye             #+#    #+#             */
/*   Updated: 2024/06/17 19:44:13 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

int	is_in_map(char **grid, int y, int x)
{
	int	i;

	i = 0;
	while (grid[i])
		i++;
	if (y < 0 || y > i)
		return (0);
	else if (x < 0 || x > (int) ft_strlen(grid[y]))
		return (0);
	return (1);
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_line(t_program *program, int step, double distance)
{
	int	i;
	int	length;
	int	holder;

	length = W_HEIGHT / distance;
	i = (W_HEIGHT / 2) - (length / 2);
	holder = i + length;
	while (i < holder)
	{
		mlx_put_pixel(program->screen, step, i, 0xFFFFFFFF);
		i++;
	}
}

void	raycasting(t_program *program)
{
	double	horizontal;
	double	vertical;
	double	angle;
	int		step;

	angle = 0;
	step = W_WIDTH;
	while (angle < (0.17 * 60))
	{
		program->player->rotation = angle;
		horizontal = get_horizontal(program);
		vertical = get_vertical(program);
		if (horizontal > vertical)
			draw_line(program, step, horizontal);
		else
			draw_line(program, step, vertical);
		angle += 0.17;
		step--;
	}
}
