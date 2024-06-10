/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:09:52 by slaye             #+#    #+#             */
/*   Updated: 2024/06/10 14:38:32 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

int	is_args(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error(ERR_ARGS), FALSE);
	else if (ft_strrchr(argv[1], '.') == FALSE)
		return (ft_error(ERR_ARGS), FALSE);
	else if (ft_strlen(ft_strrchr(argv[1], '.')) != 4)
		return (ft_error(ERR_ARGS), FALSE);
	else if (ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 4) != FALSE)
		return (ft_error(ERR_ARGS), FALSE);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	if (is_args(argc, argv) == FALSE)
		return (1);
	else
		return (0);
	return (0);
}