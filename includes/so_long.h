/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:12:47 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/23 18:51:53 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*******************	INCLUDES		**************************************/

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdbool.h>

/*******************	DEFINES			**************************************/

# define WIDTH_WINDOW 1280
# define HEIGHT_WINDOW 640

# define IMGSIZE 64

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

/*******************	STRUCTURES		**************************************/

typedef struct s_map {
	char	**map;
	char	**cloned_map;
	size_t	nb_of_rows;
	size_t	nb_of_cols;
	int		collectible_c;
	int		exit_c;
	int		player;
	int		exit;
	int		collectible;
}				t_map;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*hero;
	void	*floor;
	void	*wall;
	void	*colect;
	void	*exit;
	int		x_hero;
	int		y_hero;
	int		moves;
	int		width;
	int		height;
	t_map	map_vars;
}				t_vars;

/*******************	SO_LONG.C		**************************************/
void	ft_set_sprites(t_vars *vars);
void	ft_init_vars(t_vars *vars);
int		main(int ac, char **av);

/*******************	PARSING.C		**************************************/
bool	ft_is_rectangle(t_vars *vars);
bool	ft_check_map(char **av, t_vars *vars);
bool	ft_check_walls(t_vars *vars);
bool	ft_check_content(t_vars *vars);
bool	ft_check_param(int ac, char **av, t_vars *vars);

/*******************	PARSING_UTILS.C	**************************************/
bool	ft_check_content3(t_vars *vars);
void	ft_check_content2(t_vars *vars);
bool	ft_check_map2(char *full, int read_return, t_vars *vars);
bool	ft_invalid_arg_num(int ac);
bool	ft_check_mapfile_format(char **av);

/*******************	PATHFINDING.C	**************************************/
int		ft_check_collect(t_vars *vars);
void	ft_backtracking(t_vars *vars, size_t x, size_t y);
bool	is_finishable(t_vars *vars);
bool	ft_pathfinding(t_vars *vars);

/*******************	PRINT_MAP.C		**************************************/
void	ft_put_sprite(t_vars *vars, void *sprite, int y, int x);
void	ft_display_env(t_vars *vars);
void	ft_display_content(t_vars *vars);
int		ft_display_world(t_vars *vars);
void	ft_display_game(t_vars *vars);

/*******************	MOVES.C			**************************************/
void	ft_move_up(t_vars *vars);
void	ft_move_down(t_vars *vars);
void	ft_move_left(t_vars *vars);
void	ft_move_right(t_vars *vars);
int		ft_hook_events(int keycode, t_vars *vars);

/*******************	MOVES_UTILS.C	**************************************/
void	ft_up_game(t_vars *vars, int x, int y);
void	ft_down_game(t_vars *vars, int x, int y);
void	ft_left_game(t_vars *vars, int x, int y);
void	ft_right_game(t_vars *vars, int x, int y);

/*******************	SHUT_DOWN.C		**************************************/
int		ft_close_and_free(t_vars *vars);
int		ft_quit(t_vars *vars);
int		ft_quit_early(t_vars *vars, char *full);
void	ft_error(char *str);

#endif