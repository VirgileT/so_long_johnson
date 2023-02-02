/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:38:44 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/02 14:39:01 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_move_up(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_floor, vars->x_hero, vars->y_hero);
	vars->y_hero -= 32;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_hero, vars->x_hero, vars->y_hero);
}

void ft_move_down(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_floor, vars->x_hero, vars->y_hero);
	vars->y_hero += 32;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_hero, vars->x_hero, vars->y_hero);
}

void ft_move_left(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_floor, vars->x_hero, vars->y_hero);
	vars->x_hero -= 32;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_hero, vars->x_hero, vars->y_hero);
}

void ft_move_right(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_floor, vars->x_hero, vars->y_hero);
	vars->x_hero += 32;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_hero, vars->x_hero, vars->y_hero);
}

int ft_hook_events(int keycode, t_vars *vars)
{
	ft_printf("key = [%d]\n", keycode);
	
	if(keycode == 65307)  // ajouter destroy image hero / wall / etc ...
	{
		mlx_destroy_image(vars->mlx, vars->img_floor);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	if ((keycode == W_KEY || keycode == UP) && vars->y_hero != 32) // haut
		ft_move_up(vars);
	if ((keycode == S_KEY || keycode == DOWN) && vars->y_hero < HEIGHT_WINDOW - 64) // bas
		ft_move_down(vars);
	if ((keycode == A_KEY || keycode == LEFT) && vars->x_hero != 32)  // gauche
		ft_move_left(vars);
	if ((keycode == D_KEY || keycode == RIGHT) && vars->x_hero < WIDTH_WINDOW - 64) // droite
		ft_move_right(vars);
	return (0);
}