/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:12:47 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/17 19:41:21 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdbool.h>

/*******************	DEFINE		************/

# define WIDTH_WINDOW 1280
# define HEIGHT_WINDOW 640

# define IMGSIZE 32
//# define READ_SIZE 821

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

/*******************	STRUCTURES	************/

typedef struct	s_map {
	char **map;
	char **cloned_map;
	size_t nb_of_rows;
	size_t nb_of_cols;
	int collectible_c;
	int exit_c;
	int player;
	int exit;
	int collectible;
	// int	map_rows;
	// int	map_columns;	
}				t_map;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*hero;
	void	*floor;
	void	*wall;
	void	*colect;
	void	*exit;
	// char	*addr;
	int		x_hero;
	int		y_hero;
	int		moves;
	// int		x_floor;
	// int		y_floor;
	int		width;
	int		height;
	t_map	map_vars;
}				t_vars;



/*******************	MOVES.C		************/
int		ft_hook_events(int keycode, t_vars *vars);
void	ft_move_up(t_vars *vars);
void	ft_move_down(t_vars *vars);
void	ft_move_left(t_vars *vars);
void	ft_move_right(t_vars *vars);

/*******************	ERRORS.C	************/
bool	ft_invalid_arg_num(int ac);
bool	ft_check_mapfile_format(char **av);
void 	ft_exit(t_vars *vars);

/*******************	MAP.C		************/
bool	ft_check_param(int ac, char **av, t_vars *vars);
bool	ft_check_map(char **av, t_vars *vars);
bool 	ft_is_rectangle(t_vars *vars);
bool 	ft_check_walls(t_vars *vars);
bool	ft_check_content(t_vars *vars);

/*******************	PATHFINDING.C		************/

bool	ft_pathfinding(t_vars *vars);
void	ft_backtracking(t_vars *vars, size_t x, size_t y);
bool	is_finishable(t_vars *vars);
int		ft_check_collect(t_vars *vars);

/*******************	PRINTMAP.C		************/
void	ft_display_game(t_vars *vars);
void	ft_put_sprite(t_vars *vars, void *sprite, int y, int x);
void	ft_display_content(t_vars *vars);
int		ft_display_world(t_vars *vars);

/*******************	UTILS.C		************/
void	ft_set_sprites(t_vars *vars);
int 	ft_close_and_free(t_vars *vars); //in so_long.c

#endif