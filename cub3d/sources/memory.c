/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:04:16 by slaye             #+#    #+#             */
/*   Updated: 2024/06/10 15:16:17 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	fexit(t_program *program, int code, char *value, int fd)
{
	free(program);
	ft_putendl_fd(value, fd);
	exit(code);
}
