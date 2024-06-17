/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_horizontal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:12:48 by slaye             #+#    #+#             */
/*   Updated: 2024/06/17 19:45:20 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	horizontal_upper(t_player *player, t_ray *ray)
{
	if (ray->dist == 0)
	{
		ray->cY = player->y - floor(player->y) + OFFSET;
		ray->cX = fabs(ray->cY / tan(player->rotation));
		ray->dist += sqrt(ray->cY * ray->cY + ray->cX * ray->cX);
		ray->pY = floor(player->y - ray->cY);
		ray->pX = floor(player->x + ray->cX);
	}
	else
	{
		ray->cY += SCELL;
		ray->cX += fabs(ray->cY / tan(player->rotation));
		ray->dist += sqrt(ray->cY * ray->cY + ray->cX * ray->cX);
		ray->pY = floor(player->y - ray->cY);
		ray->pX = floor(player->x + ray->cX);
	}
}

void	horizontal_lower(t_player *player, t_ray *ray)
{
	if (ray->dist == 0)
	{
		ray->cY = player->y - floor(player->y) + OFFSET;
		ray->cX = ray->cY / tan(player->rotation);
		ray->dist += sqrt(ray->cY * ray->cY + ray->cX * ray->cX);
		ray->pY = floor(player->y + ray->cY);
		ray->pX = floor(player->x + ray->cX);
	}
	else
	{
		ray->cY += SCELL;
		ray->cX += ray->cY / tan(player->rotation);
		ray->dist += sqrt(ray->cY * ray->cY + ray->cX * ray->cX);
		ray->pY = floor(player->y + ray->cY);
		ray->pX = floor(player->x + ray->cX);
	}
}

double	get_horizontal(t_program *program)
{
	t_player	*player;
	t_ray		ray;

	player = program->player;
	ray.pX = floor(player->x);
	ray.pY = floor(player->y);
	ray.dist = 0;
	while (is_in_map(program->map->grid, ray.pY, ray.pX) && program->map->grid[(int) ray.pY][(int) ray.pX] != WALL)
	{
		if (player->rotation == 0 || player->rotation == PI)
			break ;
		else if (player->rotation > 0 && player->rotation < PI)
			horizontal_upper(player, &ray);
		else
			horizontal_lower(player, &ray);
	}
	return (ray.dist);
}
