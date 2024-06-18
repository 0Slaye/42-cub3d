/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:44:59 by slaye             #+#    #+#             */
/*   Updated: 2024/06/18 14:40:34 by slaye            ###   ########.fr       */
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
	if (length > W_HEIGHT)
		length = W_HEIGHT;
	i = (W_HEIGHT / 2) - (length / 2);
	holder = i + length;
	while (i < holder)
		mlx_put_pixel(program->screen, step, i++, 0xFFFFFFFF);
}

void	raycasting(t_program *program)
{
	double	horizontal;
	double	vertical;

	program->player->rotation = PI / 2;
	horizontal = get_horizontal(program);
	vertical = get_vertical(program);
	if (horizontal > vertical)
		draw_line(program, W_WIDTH / 2, horizontal);
	else
		draw_line(program, W_WIDTH / 2, vertical);
}
