/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:00:41 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/16 07:03:19 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

// en executant le programme, on doit donner le chemin d'acces a fichier map (ac strictement = 2)
bool ft_invalid_arg_num(int ac)
{
	if (ac > 2)
	{
		ft_printf("ERROR : too many arguments\n");
		return (false);
	}
	else if (ac < 2)
	{
		ft_printf("ERROR : argument missing\n");
		return (false);
	}
	else
		return (true);
}

// le fichier map doit etre au format .ber | strnstr cherche la string ".ber" dans la string av[1]
bool ft_check_mapfile_format(char **av)
{
	int map_file_len;
	
	map_file_len = ft_strlen(av[1]);
	
	if (!ft_strnstr(&av[1][map_file_len - 4], ".ber", 4))
	{
		ft_printf("ERREUR : mauvais format de fichier\n");
		return (false);
	}
	else
		return (true);
}

void ft_exit(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->floor);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);	
}