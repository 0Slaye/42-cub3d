/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:10:53 by slaye             #+#    #+#             */
/*   Updated: 2024/06/10 15:25:34 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMONS_H
# define COMMONS_H

# include <stdio.h>
# include <unistd.h>
# include "../sources/libft/libft.h"

# define EX_SUCCESS 0
# define EX_FAILURE 1
# define EX_ARG_FAILURE 2
# define DB_END "Success\ncub3d: program exited."
# define ER_MALLOC "Error\ncub3d: malloc function failed."
# define ER_ARGS "Error\ncub3d: wrong parameters."

typedef struct map
{
	char	**grid;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	
}	t_map;

typedef struct program
{
	int		argc;
	char	**argv;
	t_map	*map;
	
}	t_program;

// Main
void	fexit(t_program *program, int code, char *value, int fd);

// Parser
void	parser(t_program *program);

#endif