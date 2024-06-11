/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:04:16 by slaye             #+#    #+#             */
/*   Updated: 2024/06/11 18:12:06 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	free_lst(t_list *lst)
{
	t_list	*holder;

	while (lst)
	{
		holder = lst;
		lst = lst->next;
		free(holder);
	}
}

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
	if (map->lst_grid)
		free_lst(map->lst_grid);
	if (map->grid)
		free(map->grid);
	if (map)
		free(map);
}

void	fexit(t_program *program, int code, char *value, int fd)
{
	fmap(program->map);
	if (program->fd != -1)
		close(program->fd);
	free(program);
	ft_putendl_fd(value, fd);
	exit(code);
}
