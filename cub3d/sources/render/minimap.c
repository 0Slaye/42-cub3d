/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:52:49 by mde-lang          #+#    #+#             */
/*   Updated: 2024/06/19 16:39:08 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	draw_square(t_program *p, int x, int y, uint32_t color) 
{
	int	yy;
	int	xx;
	int	holder;

	yy = y + SQUARE;
	xx = x + SQUARE;
	holder = x;
	while (y < yy)
	{
		x = holder;
		while (x < xx)
			mlx_put_pixel(p->minimap, x++, y, color);
		y++;
	}
}

void draw_map(t_program *p)
{
	int	x;
	int	y;

	y = 0;
	while (y < ft_lstsize(p->map->lst_grid)) // y axis
	{
		x = 0;
		while (x < (int)ft_strlen(p->map->grid[y]))
		{
			if (p->map->grid[y][x] == '1')
				draw_square(p, x * SQUARE, y * SQUARE, 0xFFFFFFFF); // murs blanc
			else
				draw_square(p, x * SQUARE, y * SQUARE, 0x000000FF);
			x++;
		}
		y++;
	}
}
