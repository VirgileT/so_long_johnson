/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:24:32 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/03 16:24:35 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_check_map(char **av, t_vars *vars)
{
	int map_fd;
	char *line_temp;
	(void)vars;

	map_fd = open(av[1], O_RDONLY);
	if (map_fd == -1)
		ft_printf("ERREUR : Map is not valid");
	while(1)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break;
		ft_printf("%s\n", line_temp);
	}
}

bool	ft_check_param(int ac, char **av, t_vars *vars)
{
	(void)vars;
	
	// check du nombre d'arguments
	if (!ft_invalid_arg_num(ac))
		return (false);

	// check du format .ber
	if (!ft_check_mapfile_format(av))	
		return (false);	
	
	// check du display de la map
	ft_check_map(av, vars);
	
	return true;
}