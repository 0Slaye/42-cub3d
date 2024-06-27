/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:44:59 by slaye             #+#    #+#             */
/*   Updated: 2024/06/27 14:50:58 by slaye            ###   ########.fr       */
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

mlx_texture_t	*get_tex(t_program *program, t_line line)
{
	if (line.type == 0 && program->player->rayrot < PI)
		return (program->t_no);
	else if (line.type == 0 && program->player->rayrot > PI)
		return (program->t_so);
	else if (line.type != 0 && \
	(program->player->rayrot < PI / 2 || program->player->rayrot > 3 * PI / 2))
		return (program->t_ea);
	else
		return (program->t_we);
}

int	is_in_tex(uint32_t y, uint32_t x)
{
	if (y >= W_HEIGHT)
		return (0);
	else if (x >= W_WIDTH)
		return (0);
	return (1);
}

void	loop_line(t_program *program, t_line line)
{
	mlx_texture_t	*tex;

	tex = get_tex(program, line);
	while (line.i < line.max && line.i < W_HEIGHT)
	{
		if (line.type == 0 && program->player->rayrot < PI)
		{
			if (line.step < W_WIDTH && line.step >= 0 && line.i >= 0 && line.i < W_HEIGHT)
			{
				mlx_put_pixel(program->screen, line.step, line.i, get_pixel_color(\
				tex->pixels, \
				tex->width, \
				line.p1 * tex->width, \
				line.j * tex->width / (W_HEIGHT / line.distance)));
			}
		}

		else if (line.type == 0 && program->player->rayrot > PI)
		{
			if (line.step < W_WIDTH && line.step >= 0 && line.i >= 0 && line.i < W_HEIGHT)
			{
				mlx_put_pixel(program->screen, line.step, line.i, \
				get_pixel_color(tex->pixels, tex->width, \
				fabs(line.p1 - 1.0) * tex->width, line.j * tex->width / (W_HEIGHT / line.distance)));
			}
		}
		else if (line.type != 0 && (program->player->rayrot < PI / 2 \
		|| program->player->rayrot > 3 * PI / 2) && is_in_tex(line.p2 * tex->width, line.j * tex->width / line.l))
		{
			if (line.step < W_WIDTH && line.step >= 0 && line.i >= 0 && line.i < W_HEIGHT)
			{
				mlx_put_pixel(program->screen, line.step, line.i, \
				get_pixel_color(tex->pixels, tex->width, line.p2 * tex->width, \
				line.j * tex->width / (W_HEIGHT / line.distance)));
			}
		}
		else if (line.step < W_WIDTH && line.step >= 0 && line.i >= 0 && line.i < W_HEIGHT)
		{
			mlx_put_pixel(program->screen, line.step, line.i, \
			get_pixel_color(tex->pixels, tex->width, \
			fabs(line.p2 - 1) * tex->width, line.j * tex->width / (W_HEIGHT / line.distance)));
		}
		line.i++;
		line.j++;
	}
}

void	draw_line(t_program *program, t_raycaster *rc, int type)
{
	t_line	line;

	line.step = W_WIDTH - rc->i;
	line.type = type;
	if (type == 0)
		line.distance = rc->horizontal;
	else
		line.distance = rc->vertical;
	line.fisheye = program->player->rotation - program->player->rayrot;
	line.fisheye = a_normalize(line.fisheye);
	line.distance = line.distance * cos(line.fisheye);
	line.l = W_HEIGHT / line.distance;
	line.j = 0;
	if (line.l > W_HEIGHT)
	{
		line.j = (line.l - W_HEIGHT) / 2;
		line.l = W_HEIGHT;
	}
	line.i = (W_HEIGHT / 2) - (line.l / 2);
	line.max = line.i + line.l;
	line.p1 = (program->player->x + cos(program->player->rayrot) \
	* line.distance / cos(line.fisheye));
	line.p2 = (program->player->y - sin(program->player->rayrot) \
	* line.distance / cos(line.fisheye));
	line.p1 -= floor(line.p1);
	line.p2 -= floor(line.p2);
	loop_line(program, line);
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
		rc.holder = a_normalize(rc.holder);
		program->player->rayrot = rc.holder;
		rc.horizontal = get_horizontal(program);
		rc.vertical = get_vertical(program);
		if (rc.horizontal < rc.vertical)
			draw_line(program, &rc, 0);
		else
			draw_line(program, &rc, 1);
		rc.i++;
		rc.holder += rc.step;
	}
}
