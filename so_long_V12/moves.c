/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:38:44 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/16 17:26:28 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void ft_move_up(t_vars *vars)
{
	int x;
	int y;

	// update la position du hero
	// update la map
	// update les img

	x = vars->x_hero / vars->width;
	y = vars->y_hero / vars->height;
	if (vars->map_vars.map[y - 1][x] != '1')
	{
		if (vars->map_vars.map[y - 1][x] != 'E')
		{
			vars->map_vars.map[y - 1][x] = 'P';
			vars->map_vars.map[y][x] = '0';
			vars->moves++;
			ft_put_sprite(vars, vars->hero, y - 1, x);
			ft_put_sprite(vars, vars->hero, y, x);
			ft_printf("moves = [%d]\n", vars->moves);
		}
		else if (ft_check_collect(vars) == 0)
		{
			ft_printf("You win ! moves to win : %d. Can you do better ?\n", vars->moves);
			ft_close_and_free(vars);
		}
	}
}


void ft_move_down(t_vars *vars)
{
	int x;
	int y;

	x = vars->x_hero / vars->width;
	y = vars->y_hero / vars->height;
	if (vars->map_vars.map[y + 1][x] != '1')
	{
		if (vars->map_vars.map[y + 1][x] != 'E')
		{
			vars->map_vars.map[y + 1][x] = *vars->hero;
			vars->map_vars.map[y][x] = *vars->floor;
			vars->moves++;
			ft_printf("moves = [%d]\n", vars->moves);
		}
		else
		{
			if (ft_check_collect(vars) == 0)
			{
				ft_printf("You win ! moves to win : %d. Can you do better ?\n",
					vars->moves);
				ft_close_and_free(vars);
			}
		}
	}
}

void ft_move_left(t_vars *vars)
{
	int x;
	int y;

	x = vars->x_hero / vars->width;
	y = vars->y_hero / vars->height;
	if (vars->map_vars.map[y][x - 1] != '1')
	{
		if (vars->map_vars.map[y][x - 1] != 'E')
		{
			vars->map_vars.map[y][x - 1] = *vars->hero;
			vars->map_vars.map[y][x] = *vars->floor;
			vars->moves++;
			ft_printf("moves = [%d]\n", vars->moves);
		}
		else
		{
			if (ft_check_collect(vars) == 0)
			{
				ft_printf("You win ! moves to win : %d. Can you do better ?\n",
					vars->moves);
				ft_close_and_free(vars);
			}
		}
	}
}

void ft_move_right(t_vars *vars)
{
	int x;
	int y;

	x = vars->x_hero / vars->width;
	y = vars->y_hero / vars->height;
	if (vars->map_vars.map[y][x + 1] != '1')
	{
		if (vars->map_vars.map[y][x + 1] != 'E')
		{
			vars->map_vars.map[y][x + 1] = *vars->hero;
			vars->map_vars.map[y][x] = *vars->floor;
			vars->moves++;
			ft_printf("moves = [%d]\n", vars->moves);
		}
		else
		{
			if (ft_check_collect(vars) == 0)
			{
				ft_printf("You win ! moves to win : %d. Can you do better ?\n",
					vars->moves);
				ft_close_and_free(vars);
			}
		}
	}
}

int ft_hook_events(int keycode, t_vars *vars)
{
	ft_printf("key = [%d]\n", keycode); // a retirer
	
	if(keycode == 65307)  // ajouter destroy image hero / wall / etc ...
	{
		ft_close_and_free(vars);
	}
	if ((keycode == W_KEY || keycode == UP)) // haut
		ft_move_up(vars);
	if ((keycode == S_KEY || keycode == DOWN)) // bas
		ft_move_down(vars);
	if ((keycode == A_KEY || keycode == LEFT))  // gauche
		ft_move_left(vars);
	if ((keycode == D_KEY || keycode == RIGHT)) // droite
		ft_move_right(vars);
	return (0);
}