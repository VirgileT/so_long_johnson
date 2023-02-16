/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:45:43 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/16 17:13:40 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void ft_set_sprites(t_vars *vars)
{
	//ULYSSE :int a = 32;
	// vars->width = 32;
	// vars->height = 32;

	dprintf(2, "yoooooooooooooooooo\n");
	vars->hero = mlx_xpm_file_to_image(vars->mlx, "xpm/hero.xpm", &(vars->width), &(vars->height));
	dprintf(2, "hereeeeeeeeeeee\n");
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "xpm/wall.xpm", &(vars->width), &(vars->height));
	vars->floor = mlx_xpm_file_to_image(vars->mlx, "xpm/floor.xpm", &(vars->width), &(vars->height));
	vars->colect = mlx_xpm_file_to_image(vars->mlx, "xpm/colect.xpm", &(vars->width), &(vars->height));
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "xpm/exit.xpm", &(vars->width), &(vars->height));
}