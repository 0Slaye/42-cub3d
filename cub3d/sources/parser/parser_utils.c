/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:44:13 by slaye             #+#    #+#             */
/*   Updated: 2024/06/10 15:46:22 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	set_map_data(t_map *map, char *value)
{
	(void) map;
	if (ft_strncmp(value, "NO ", 3) == 0)
		printf("NO detected.\n");
	if (ft_strncmp(value, "SO ", 3) == 0)
		printf("SO detected.\n");
	if (ft_strncmp(value, "WE ", 3) == 0)
		printf("WE detected.\n");
	if (ft_strncmp(value, "EA ", 3) == 0)
		printf("EA detected.\n");
	if (ft_strncmp(value, "F ", 2) == 0)
		printf("F detected.\n");
	if (ft_strncmp(value, "C ", 2) == 0)
		printf("C detected.\n");
}
