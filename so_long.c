/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:02:27 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/23 17:54:57 by vtestut          ###   ########.fr       */
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
	vars->width = 64;
	vars->height = 64;
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

int	main(int ac, char **av)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	ft_init_vars(&vars);
	if (!ft_check_param(ac, av, &vars))
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		exit(0);
	}
	if (!ft_pathfinding(&vars))
		ft_close_and_free(&vars);
	ft_set_sprites(&vars);
	ft_display_game(&vars);
	ft_close_and_free(&vars);
	return (0);
}
