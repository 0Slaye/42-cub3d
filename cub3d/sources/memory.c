/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:04:16 by slaye             #+#    #+#             */
/*   Updated: 2024/06/10 17:05:07 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	fmap(t_map *map)
{
	if (map->file)
		ft_lstclear(&map->file, &free);
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	if (map->f)
		free(map->f);
	if (map->c)
		free(map->c);
	if (map)
		free(map);
}

void	fexit(t_program *program, int code, char *value, int fd)
{
	fmap(program->map);
	free(program);
	ft_putendl_fd(value, fd);
	exit(code);
}
