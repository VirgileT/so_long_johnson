/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:45:43 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/17 20:07:52 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void ft_set_sprites(t_vars *vars)
{
	//ULYSSE :
	int a;
	int	b;
	// vars->width = 32;
	// vars->height = 32;

	a = 32;
	b = 32;
	// dprintf(2, "a=[%d]\n", a);
	// dprintf(2, "b=[%d]\n", b);
	dprintf(2, "yoooooooooooooooooo\n");
	// vars->hero = malloc(sizeof(void *) * 1);
	vars->hero = mlx_xpm_file_to_image(vars->mlx, "xpm/hero.xpm", &b, &a);
	dprintf(2, "hereeeeeeeeeeee\n");
	// vars->wall = mlx_xpm_file_to_image(vars->mlx, "xpm/wall.xpm", &a, &a);
	// vars->floor = mlx_xpm_file_to_image(vars->mlx, "xpm/floor.xpm", &a, &a);
	// vars->colect = mlx_xpm_file_to_image(vars->mlx, "xpm/colect.xpm", &a, &a);
	// vars->exit = mlx_xpm_file_to_image(vars->mlx, "xpm/exit.xpm", &a, &a);
}