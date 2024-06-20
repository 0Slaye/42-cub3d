/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:44:59 by slaye             #+#    #+#             */
/*   Updated: 2024/06/20 13:49:51 by slaye            ###   ########.fr       */
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
	int		i;
	int		length;
	int		holder;
	double	fisheye;

	fisheye = program->player->rotation - program->player->rayrot;
	if (fisheye < 0)
		fisheye += (2 * PI);
	if (fisheye > (2 * PI))
		fisheye -= (2 * PI);
	distance *= cos(fisheye);
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
	t_raycaster	rc;

	rc.i = 1;
	rc.rays = W_WIDTH / 2;
	rc.step = PI / 3 / rc.rays;
	rc.holder = program->player->rotation - (PI / 3 / 2);
	while (rc.i <= rc.rays)
	{
		if (rc.holder < 0)
			rc.holder += (2 * PI);
		if (rc.holder > (2 * PI))
			rc.holder -= (2 * PI);
		program->player->rayrot = rc.holder;
		rc.horizontal = get_horizontal(program);
		rc.vertical = get_vertical(program);
		if (rc.horizontal < rc.vertical)
			draw_line(program, W_WIDTH - rc.i, rc.horizontal);
		else
			draw_line(program, W_WIDTH - rc.i, rc.vertical);
		rc.i++;
		rc.holder += rc.step;
	}
}
