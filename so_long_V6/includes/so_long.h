/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:12:47 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/03 16:12:42 by vtestut          ###   ########.fr       */
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

# define WIDTH_IMAGE 32
# define HEIGHT_IMAGE 32

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
	unsigned int	nb_lines;
	unsigned int	line_len;
	unsigned int	map_rows;
	unsigned int	map_columns;
}				t_map;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img_hero;
	void	*img_floor;
	char	*addr;
	int		x_hero;
	int		y_hero;
	int		x_floor;
	int		y_floor;
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
void	ft_check_map(char **av, t_vars *vars);



#endif