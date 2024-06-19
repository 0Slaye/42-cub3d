/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:10:53 by slaye             #+#    #+#             */
/*   Updated: 2024/06/19 15:56:09 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMONS_H
# define COMMONS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../sources/libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define DB_END "Success\ncub3D: program exited."
# define ER_MALLOC "Error\ncub3D: malloc function failed."
# define ER_ARGS "Error\ncub3D: wrong parameters."
# define ER_OPEN "Error\ncub3D: open function failed."
# define ER_MAP "Error\ncub3D: map incorrect."
# define ER_MLX "Error\ncub3D: mlx system failed."

# define EMPTY '0'
# define WALL '1'
# define NORD 'N'
# define SOUTH 'S'
# define EST 'E'
# define WEST 'W'
# define W_WIDTH 1024
# define W_HEIGHT 512

#define MOVE 0.02

# define SCELL 1.0
# define SQUARE 16
# define PI 3.14159265358979323846
# define OFFSET 0.000001

typedef struct map
{
	t_list		*file;		// .cub
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	uint32_t	sq_x;
	uint32_t	sq_y;	
	t_list		*lst_grid;	// map
	char		**grid; 	// map
}	t_map;

typedef struct player
{
	int		spawn;
	double	x;
	double	y;
	double	rotation;
	double	rayrot;
}	t_player;

typedef struct ray
{
	double	cX;
	double	cY;
	double	pX;
	double	pY;
	double	dist;
}	t_ray;

typedef struct program
{
	t_player	*player;
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*screen;
	mlx_image_t	*minimap;
	char		**argv;
	int			argc;
	int			fd;
}	t_program;

// Main
void		fexit(t_program *program, int code, char *value, int fd);
void		free_split(char **split);

// Parser
void		parser(t_program *program);
void		set_map_vars_loop(t_program *program, char *value);
int			set_map_grid_loop(char *line);
int			is_map_chars(char *line);
void		set_map_grid(t_program *program);
void		remove_nl(char *value);
void		map_checker(t_program *program);
void		check_cell_border(t_program *program, char **grid, int y, int x);

// Render
void		s_window(t_program *program);
void		hooks(void *program);
t_player	*s_player(t_program *program);
void		raycasting(t_program *program);
double		get_horizontal(t_program *program);
double		get_vertical(t_program *program);
int			is_in_map(char **grid, int y, int x);
void		fc_printer(t_program *program);
void		draw_map(t_program *p);

#endif

// free mlx
// check leaks