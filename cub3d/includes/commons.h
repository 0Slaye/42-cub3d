/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:10:53 by slaye             #+#    #+#             */
/*   Updated: 2024/06/10 14:31:16 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMONS_H
# define COMMONS_H

# include <stdio.h>
# include <unistd.h>
# include "../sources/libft/libft.h"

# define TRUE 1
# define FALSE 0
# define ERR_ARGS "cub3d: Wrong parameters."

void	ft_error(char *value);

# endif