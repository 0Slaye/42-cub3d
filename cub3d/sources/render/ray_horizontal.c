/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_horizontal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:12:48 by slaye             #+#    #+#             */
/*   Updated: 2024/06/18 19:37:43 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	horizontal_upper(t_player *player, t_ray *ray)
{
	if (ray->dist == 0)
	{
		ray->cY = player->y - floor(player->y) + OFFSET;
		ray->cX = ray->cY / tan(player->rayrot);
		ray->dist += sqrt(ray->cY * ray->cY + ray->cX * ray->cX);
		ray->pY = floor(player->y - ray->cY);
		ray->pX = floor(player->x + ray->cX);
	}
	else
	{
		ray->cY += SCELL;
		ray->cX += SCELL / tan(player->rayrot);
		ray->dist += sqrt(SCELL + (SCELL / tan(player->rayrot)) * (SCELL / tan(player->rayrot)));
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
	if (player->rayrot == 0 || player->rayrot == PI)
		return (99999999);
	while (is_in_map(program->map->grid, ray.pY, ray.pX) && program->map->grid[(int) ray.pY][(int) ray.pX] != WALL)
	{
		if (player->rotation > 0 && player->rotation < PI)
			horizontal_upper(player, &ray);
		else
			horizontal_lower(player, &ray);
	}
	return (ray.dist);
}
