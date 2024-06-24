/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:38:39 by slaye             #+#    #+#             */
/*   Updated: 2024/06/24 16:21:36 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

double	a_normalize(double angle)
{
	double	result;

	result = angle;
	if (result < 0)
		result += (2 * PI);
	if (result > (2 * PI))
		result -= (2 * PI);
	return (result);
}

unsigned int	get_pixel_color(uint8_t *pixels, int width, int x, int y)
{
	int	index;

	index = (y * width + x) * 4;
	return (ft_pixel(pixels[index], pixels[index + 1], \
	pixels[index + 2], pixels[index + 3]));
}
