/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:02:27 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/16 09:23:38 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"


void ft_init_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->hero = NULL;
	vars->wall = NULL;
	vars->floor = NULL;
	vars->colect = NULL;
	vars->exit = NULL;
	//vars->addr = NULL;
	vars->x_hero = 0;
	vars->y_hero = 0;
	vars->moves = 0;
	// vars->x_floor = 0;
	// vars->y_floor = 0;
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
	// vars->map_vars.map_rows = 0;
	// vars->map_vars.map_columns = 0;
}

int ft_close_and_free(t_vars *vars)
{
	int		i;

	i = 0;
	if (vars->map_vars.map != NULL)
	{
		while (vars->map_vars.map[i] != NULL)
		{
			free(vars->map_vars.map[i]);
			i++;
		}
		free(vars->map_vars.map);
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
    
int	main(int ac, char **av)
{
	t_vars	vars;
	
	vars.mlx = mlx_init();

	ft_init_vars(&vars);
	if(!ft_check_param(ac, av, &vars))
		exit(0);
	if(!ft_pathfinding(&vars))
		exit(0);
	ft_set_sprites(&vars);
	ft_display_game(&vars);
	ft_close_and_free(&vars);
	return (0);
}