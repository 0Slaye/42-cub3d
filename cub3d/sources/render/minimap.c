/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:52:49 by mde-lang          #+#    #+#             */
/*   Updated: 2024/06/18 19:39:16 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	draw_square(t_program *p, int x, int y, uint32_t color) 
{
	while (p->map->sq_y < (uint32_t)(SQUARE * y))
	{
		while (p->map->sq_x < (uint32_t)(SQUARE  * x))
		{
			mlx_put_pixel(p->minimap, p->map->sq_x, p->map->sq_y, color); // changer l'image
			p->map->sq_x++;
		}
		p->map->sq_x -= SQUARE;
		p->map->sq_y++;
	}
	p->map->sq_x += SQUARE;
	p->map->sq_y -= SQUARE;
}

void draw_map(t_program *p)
{
	int	x;
	int	y;

	y = 0;
	while (y < ft_lstsize(p->map->lst_grid))
	{
		x = 0;
		while (x < (int)ft_strlen(p->map->grid[y]))
		{
			printf("1\n");
			if (p->map->grid[y][x] == '1')
				draw_square(p, x + 1, y + 1, 0xFFFFFFFF); // murs blanc
			else if (p->map->grid[y][x] == '0')
				draw_square(p, x + 1, y + 1, 0x000000FF);
			// else if (p->map->grid[y][x] == '0' || p->map->grid[y][x] == 'N' || p->map->grid[y][x] == 'S' 
			// 	|| p->map->grid[y][x] == 'W' || p->map->grid[y][x] == 'E')
			// 	draw_square(p, x + 1, y + 1, 0x000000FF);
			x++;
		}
		y++;
	}
}
