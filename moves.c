/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:38:44 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/23 16:43:31 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_move_up(t_vars *vars)
{
	static int	x;
	static int	y;

	x = vars->x_hero / vars->width;
	y = vars->y_hero / vars->height;
	if (vars->map_vars.map[y - 1][x] != '1')
	{
		if (vars->map_vars.map[y - 1][x] != 'E')
			ft_up_game(vars, x, y);
		else if ((ft_check_collect(vars) == 0)
			&& (vars->map_vars.map[y - 1][x] == 'E'))
		{
			vars->map_vars.map[y - 1][x] = 'P';
			vars->map_vars.map[y][x] = '0';
			vars->moves++;
			ft_put_sprite(vars, vars->hero, y - 1, x);
			ft_put_sprite(vars, vars->hero, y, x);
			ft_printf("moves = [%d]\n", vars->moves);
			ft_printf("You win ! total moves : %d.\n", vars->moves);
			ft_close_and_free(vars);
		}
	}
}

void	ft_move_down(t_vars *vars)
{
	static int	x;
	static int	y;

	x = vars->x_hero / vars->width;
	y = vars->y_hero / vars->height;
	if (vars->map_vars.map[y + 1][x] != '1')
	{
		if (vars->map_vars.map[y + 1][x] != 'E')
			ft_down_game(vars, x, y);
		else if ((ft_check_collect(vars) == 0)
			&& (vars->map_vars.map[y + 1][x] == 'E'))
		{
			vars->map_vars.map[y + 1][x] = 'P';
			vars->map_vars.map[y][x] = '0';
			vars->moves++;
			ft_put_sprite(vars, vars->hero, y + 1, x);
			ft_put_sprite(vars, vars->hero, y, x);
			ft_printf("moves = [%d]\n", vars->moves);
			ft_printf("You win ! total moves : %d.\n", vars->moves);
			ft_close_and_free(vars);
		}
	}
}

void	ft_move_left(t_vars *vars)
{
	static int	x;
	static int	y;

	x = vars->x_hero / vars->width;
	y = vars->y_hero / vars->height;
	if (vars->map_vars.map[y][x - 1] != '1')
	{
		if (vars->map_vars.map[y][x - 1] != 'E')
			ft_left_game(vars, x, y);
		else if ((ft_check_collect(vars) == 0)
			&& (vars->map_vars.map[y][x - 1] == 'E'))
		{
			vars->map_vars.map[y][x - 1] = 'P';
			vars->map_vars.map[y][x] = '0';
			vars->moves++;
			ft_put_sprite(vars, vars->hero, y, x - 1);
			ft_put_sprite(vars, vars->hero, y, x);
			ft_printf("moves = [%d]\n", vars->moves);
			ft_printf("You win ! total moves : %d.\n", vars->moves);
			ft_close_and_free(vars);
		}
	}
}

void	ft_move_right(t_vars *vars)
{
	static int	x;
	static int	y;

	x = vars->x_hero / vars->width;
	y = vars->y_hero / vars->height;
	if (vars->map_vars.map[y][x + 1] != '1')
	{
		if (vars->map_vars.map[y][x + 1] != 'E')
			ft_right_game(vars, x, y);
		else if ((ft_check_collect(vars) == 0)
			&& (vars->map_vars.map[y][x + 1] == 'E'))
		{
			vars->map_vars.map[y][x + 1] = 'P';
			vars->map_vars.map[y][x] = '0';
			vars->moves++;
			ft_put_sprite(vars, vars->hero, y, x + 1);
			ft_put_sprite(vars, vars->hero, y, x);
			ft_printf("moves = [%d]\n", vars->moves);
			ft_printf("You win ! total moves : %d.\n", vars->moves);
			ft_close_and_free(vars);
		}
	}
}

int	ft_hook_events(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_close_and_free(vars);
	if ((keycode == W_KEY || keycode == UP))
		ft_move_up(vars);
	if ((keycode == S_KEY || keycode == DOWN))
		ft_move_down(vars);
	if ((keycode == A_KEY || keycode == LEFT))
		ft_move_left(vars);
	if ((keycode == D_KEY || keycode == RIGHT))
		ft_move_right(vars);
	return (0);
}
