/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:10:53 by slaye             #+#    #+#             */
/*   Updated: 2024/06/11 15:44:36 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMONS_H
# define COMMONS_H

# include <stdio.h>
# include <unistd.h>
# include "../sources/libft/libft.h"

# define EX_SUCCESS 0
# define EX_FAILURE 1
# define DB_END "Success\ncub3d: program exited."
# define ER_MALLOC "Error\ncub3d: malloc function failed."
# define ER_ARGS "Error\ncub3d: wrong parameters."
# define ER_OPEN "Error\ncub3d: open function failed."
# define ER_MAP "Error\ncub3d: map incorrect."

typedef struct map
{
	t_list	*file;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	t_list	*grid;
}	t_map;

typedef struct program
{
	int		argc;
	char	**argv;
	t_map	*map;
	int		fd;
}	t_program;

// Main
void	fexit(t_program *program, int code, char *value, int fd);

// Parser
void	parser(t_program *program);
void	set_map_vars_loop(t_program *program, char *value);
int		set_map_grid_loop(char *line);
int		is_map_chars(char *line);
void	set_map_grid(t_program *program);
void	remove_nl(char *value);

#endif