/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:24:53 by slaye             #+#    #+#             */
/*   Updated: 2024/06/10 14:28:41 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	ft_error(char *value)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(value, STDERR_FILENO);
}