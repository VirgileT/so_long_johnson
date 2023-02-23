/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:56:49 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/23 15:40:17 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_put_sprite(t_vars *vars, void *sprite, int y, int x)
{
	mlx_put_image_to_window(vars->mlx, vars->win, sprite,
		x * IMGSIZE, y * IMGSIZE);
}

void	ft_display_env(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (vars->map_vars.map[y] != NULL)
	{
		while (vars->map_vars.map[y][x] != '\0')
		{
			if (vars->map_vars.map[y][x] == '1')
				ft_put_sprite(vars, vars->wall, y, x);
			if (vars->map_vars.map[y][x] == '0')
				ft_put_sprite(vars, vars->floor, y, x);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_display_content(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (vars->map_vars.map[y] != NULL)
	{
		while (vars->map_vars.map[y][x] != '\0')
		{
			if (vars->map_vars.map[y][x] == 'C')
				ft_put_sprite(vars, vars->colect, y, x);
			if (vars->map_vars.map[y][x] == 'E')
				ft_put_sprite(vars, vars->exit, y, x);
			if (vars->map_vars.map[y][x] == 'P')
			{
				vars->x_hero = x * vars->width;
				vars->y_hero = y * vars->height;
				ft_put_sprite(vars, vars->hero, y, x);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int	ft_display_world(t_vars *vars)
{
	ft_display_env(vars);
	ft_display_content(vars);
	return (0);
}

void	ft_display_game(t_vars *vars)
{
	const int	winwidht = IMGSIZE * vars->map_vars.nb_of_cols;
	const int	winheight = IMGSIZE * vars->map_vars.nb_of_rows;	

	vars->win = mlx_new_window(vars->mlx, winwidht, winheight, "42 school");
	if (vars->win == NULL)
	{
		free(vars->mlx);
		return ;
	}
	mlx_loop_hook(vars->mlx, ft_display_world, vars);
	mlx_key_hook(vars->win, &ft_hook_events, vars);
	mlx_hook(vars->win, 17, 0, ft_close_and_free, vars);
	mlx_loop(vars->mlx);
	ft_close_and_free(vars);
}
