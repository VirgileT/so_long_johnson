/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:02:27 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/23 15:40:11 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_set_sprites(t_vars *vars)
{
	int	a;
	int	b;

	a = 64;
	b = 64;
	vars->hero = mlx_xpm_file_to_image(vars->mlx, "xpm/hero.xpm", &b, &a);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "xpm/wall.xpm", &a, &a);
	vars->floor = mlx_xpm_file_to_image(vars->mlx, "xpm/floor.xpm", &a, &a);
	vars->colect = mlx_xpm_file_to_image(vars->mlx, "xpm/colect.xpm", &a, &a);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "xpm/exit.xpm", &a, &a);
}

void	ft_init_vars(t_vars *vars)
{
	vars->win = NULL;
	vars->hero = NULL;
	vars->wall = NULL;
	vars->floor = NULL;
	vars->colect = NULL;
	vars->exit = NULL;
	vars->x_hero = 0;
	vars->y_hero = 0;
	vars->moves = 0;
	vars->width = 32;
	vars->height = 32;
	vars->map_vars.map = NULL;
	vars->map_vars.cloned_map = NULL;
	vars->map_vars.exit_c = 0;
	vars->map_vars.nb_of_cols = 0;
	vars->map_vars.nb_of_rows = 0;
	vars->map_vars.player = 0;
	vars->map_vars.exit = 0;
	vars->map_vars.collectible = 0;
	vars->map_vars.collectible_c = 0;
}

int	ft_close_and_free(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map_vars.map != NULL)
	{
		while (vars->map_vars.map[i] != NULL)
		{
			free(vars->map_vars.map[i]);
			free(vars->map_vars.cloned_map[i]);
			i++;
		}
		free(vars->map_vars.map);
		free(vars->map_vars.cloned_map);
		mlx_destroy_image(vars->mlx, vars->wall);
		mlx_destroy_image(vars->mlx, vars->floor);
		mlx_destroy_image(vars->mlx, vars->colect);
		mlx_destroy_image(vars->mlx, vars->hero);
		mlx_destroy_image(vars->mlx, vars->exit);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

// in case an error occure before pathfinding and sprites settings
int	ft_quite(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map_vars.map != NULL)
	{
		while (vars->map_vars.map[i] != NULL)
		{
			free(vars->map_vars.map[i]);
			free(vars->map_vars.cloned_map[i]);
			i++;
		}
		free(vars->map_vars.map);
		free(vars->map_vars.cloned_map);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	ft_init_vars(&vars);
	if (!ft_check_param(ac, av, &vars))
		ft_quite(&vars);
	if (!ft_pathfinding(&vars))
		ft_close_and_free(&vars);
	ft_set_sprites(&vars);
	ft_display_game(&vars);
	ft_close_and_free(&vars);
	return (0);
}
