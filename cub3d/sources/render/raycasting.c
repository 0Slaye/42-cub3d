/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:44:59 by slaye             #+#    #+#             */
/*   Updated: 2024/06/17 16:03:52 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#define RAYS 10.0
#define ANGLE 80.0
#define SCELL 1.0
#define PI 3.14159265359
#define OFFSET 0.000001

void	horizontal_upper(t_player *player, t_ray *ray)
{
	if (ray->dist == 0)
	{
		ray->cY = player->y - floor(player->y) + OFFSET;
		ray->cX = ray->cY / tan(player->rotation);
		ray->dist += sqrt(ray->cY * ray->cY + ray->cX * ray->cX);
		ray->pY = floor(player->y - ray->cY);
		ray->pX = floor(player->x + ray->cX);
	}
	else
	{
		ray->cY += SCELL;
		ray->cX += ray->cY / tan(player->rotation);
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
	while (program->map->grid[(int) ray.pY][(int) ray.pX] != WALL)
	{
		if (player->rotation > 0 && player->rotation < PI)
			horizontal_upper(player, &ray);
		else
			horizontal_lower(player, &ray);
	}
	return (ray.dist);
}

void	raycasting(t_program *program)
{
	program->player->rotation = PI / 2;
	printf("Distance: %f\n", get_horizontal(program));
}
