/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_vertical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:12:48 by slaye             #+#    #+#             */
/*   Updated: 2024/06/17 18:14:47 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	vertical_upper(t_player *player, t_ray *ray)
{
	if (ray->dist == 0)
	{
		ray->cX = player->x - floor(player->x) + OFFSET;
		ray->cY = fabs(ray->cX * tan(player->rotation));
		ray->dist += sqrt(ray->cY * ray->cY + ray->cX * ray->cX);
		ray->pY = floor(player->y - ray->cY);
		ray->pX = floor(player->x + ray->cX);
	}
	else
	{
		ray->cX += SCELL;
		ray->cY += fabs(ray->cX * tan(player->rotation));
		ray->dist += sqrt(ray->cY * ray->cY + ray->cX * ray->cX);
		ray->pY = floor(player->y - ray->cY);
		ray->pX = floor(player->x + ray->cX);
	}
}

void	vertical_lower(t_player *player, t_ray *ray)
{
	if (ray->dist == 0)
	{
		ray->cX = player->x - floor(player->x) + OFFSET;
		ray->cY = ray->cX * tan(player->rotation);
		ray->dist += sqrt(ray->cY * ray->cY + ray->cX * ray->cX);
		ray->pY = floor(player->y + ray->cY);
		ray->pX = floor(player->x + ray->cX);
	}
	else
	{
		ray->cX += SCELL;
		ray->cY += ray->cX * tan(player->rotation);
		ray->dist += sqrt(ray->cY * ray->cY + ray->cX * ray->cX);
		ray->pY = floor(player->y + ray->cY);
		ray->pX = floor(player->x + ray->cX);
	}
}

double	get_vertical(t_program *program)
{
	t_player	*player;
	t_ray		ray;

	player = program->player;
	ray.pX = floor(player->x);
	ray.pY = floor(player->y);
	ray.dist = 0;
	while (is_in_map(program->map->grid, ray.pY, ray.pX) && program->map->grid[(int) ray.pY][(int) ray.pX] != WALL)
	{
		if (player->rotation == PI / 2 || player->rotation == -PI / 2)
			break ;
		if (player->rotation > 0 && player->rotation < PI)
			vertical_upper(player, &ray);
		else
			vertical_lower(player, &ray);
	}
	return (ray.dist);
}
