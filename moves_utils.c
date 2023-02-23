/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:10:11 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/23 15:40:35 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_up_game(t_vars *vars, int x, int y)
{
	vars->map_vars.map[y - 1][x] = 'P';
	vars->map_vars.map[y][x] = '0';
	vars->moves++;
	ft_put_sprite(vars, vars->hero, y - 1, x);
	ft_put_sprite(vars, vars->floor, y, x);
	ft_printf("moves = [%d]\n", vars->moves);
}

void	ft_down_game(t_vars *vars, int x, int y)
{
	vars->map_vars.map[y + 1][x] = 'P';
	vars->map_vars.map[y][x] = '0';
	vars->moves++;
	ft_put_sprite(vars, vars->hero, y + 1, x);
	ft_put_sprite(vars, vars->floor, y, x);
	ft_printf("moves = [%d]\n", vars->moves);
}

void	ft_left_game(t_vars *vars, int x, int y)
{
	vars->map_vars.map[y][x - 1] = 'P';
	vars->map_vars.map[y][x] = '0';
	vars->moves++;
	ft_put_sprite(vars, vars->hero, y, x - 1);
	ft_put_sprite(vars, vars->floor, y, x);
	ft_printf("moves = [%d]\n", vars->moves);
}

void	ft_right_game(t_vars *vars, int x, int y)
{
	vars->map_vars.map[y][x + 1] = 'P';
	vars->map_vars.map[y][x] = '0';
	vars->moves++;
	ft_put_sprite(vars, vars->hero, y, x + 1);
	ft_put_sprite(vars, vars->floor, y, x);
	ft_printf("moves = [%d]\n", vars->moves);
}
