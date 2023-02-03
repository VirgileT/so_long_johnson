/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:02:27 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/03 16:14:06 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars ft_init_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->img_hero = NULL;
	vars->img_hero = NULL;
	vars->addr = NULL;
	vars->x_hero = 0;
	vars->y_hero = 0;
	vars->x_floor = 0;
	vars->y_floor = 0;
	vars->width = 0;
	vars->height = 0;
	vars->map_vars.line_len = 0;
	vars->map_vars.nb_lines = 0;
	vars->map_vars.map_rows = 0;
	vars->map_vars.map_columns = 0;
	return (*vars);
}

int	main(int ac, char **av)
{
	t_vars	vars;

		// initialisation de la structure
	ft_init_vars(&vars);
	
	// check la map (.ber / readable / wall etc / pathfinding)
	if(!ft_check_param(ac, av, &vars))
		exit(0);
	
	// initialisation de la mlx & de la fenetre							
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH_WINDOW, HEIGHT_WINDOW, "Hello World !");
	
	// affichage du sol		
	vars.img_floor = mlx_xpm_file_to_image(vars.mlx, "xpm/parquet.xpm", &vars.width, &vars.height);
	while (vars.x_floor < WIDTH_WINDOW && vars.y_floor < HEIGHT_WINDOW)
	{
		while (vars.x_floor < WIDTH_WINDOW)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, vars.img_floor, vars.x_floor, vars.y_floor);
			vars.x_floor+= 32;
		}
		vars.x_floor = 0;
		vars.y_floor += 32;
	}

	// affichage du personnage
	vars.img_hero = mlx_xpm_file_to_image(vars.mlx, "xpm/hero-with-floor.xpm", &vars.width, &vars.height);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img_hero, (vars.x_hero = 32), (vars.y_hero = 32));
	
	// hooks et events
	mlx_key_hook(vars.win, ft_hook_events, &vars);

	// affichage en boucle de la mlx
	mlx_loop(vars.mlx);
}