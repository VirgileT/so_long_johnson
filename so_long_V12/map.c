/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:24:32 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/16 07:23:43 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

bool ft_is_rectangle(t_vars *vars)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(vars->map_vars.map[0]);
	while (vars->map_vars.map[i] != NULL)
	{
		if (ft_strlen(vars->map_vars.map[i]) != len)
		{
			printf("ERROR : Map shape is invalid\n");
			return (false);
		}
		i++;
		vars->map_vars.nb_of_rows++;
	}
	vars->map_vars.nb_of_cols = len;
	return (true);
}

bool ft_check_map(char **av, t_vars *vars)
{
	int map_fd;
	int read_return;
	const int	max_map_width = WIDTH_WINDOW / IMGSIZE;
	const int	max_map_height = HEIGHT_WINDOW / IMGSIZE;
	const int	read_size = (max_map_width + 1) * max_map_height + 1;
	char full[read_size];

	map_fd = open(av[1], O_RDONLY);
	if (map_fd == -1)
	{
		ft_printf("ERROR : open() error !\n");
		return (false);
	}
	read_return = read(map_fd, full, read_size);
	if (read_return < 0)
	{
		printf("ERROR : read() error !\n");
		return (false);
	}
	if (read_return == read_size)
	{
		printf("ERROR : Map too big.\n");
		return (false);
	}
	full[read_return] = '\0';
	vars->map_vars.map = ft_split(full, '\n');
	vars->map_vars.cloned_map = ft_split(full, '\n');
	if (!(ft_is_rectangle(vars)))
		return (false);
	return (true);
}

bool ft_check_walls(t_vars *vars)
{
	int i;

	i = 0;
	while(vars->map_vars.map[0][i] != '\0')
	{
		if ((vars->map_vars.map[0][i] != '1') || (vars->map_vars.map[vars->map_vars.nb_of_rows - 1][i] != '1'))
		{	
			printf("BREACH IN THE WALL ('X') !!!!\n"); 
			return (false);
		}
		i++;
	}
	i = 0;
	while(vars->map_vars.map[i] != NULL)
	{
		if ((vars->map_vars.map[i][0] != '1') || (vars->map_vars.map[i][vars->map_vars.nb_of_cols - 1] != '1'))
		{
			printf("BREACH IN THE WALL ('Y') !!!!\n"); 
			return (false);
		}
		i++;
	}
	return (true);
}

bool ft_check_content(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	while(vars->map_vars.map[i] != NULL)
	{
		j = 0;
		while(vars->map_vars.map[i][j] != '\0')
		{
			if (vars->map_vars.map[i][j] == 'P')
			{
				vars->map_vars.player++;
				vars->y_hero = i;
				vars->x_hero = j;
			}
			if (vars->map_vars.map[i][j] == 'C')
				vars->map_vars.collectible++;
			if (vars->map_vars.map[i][j] == 'E')
				vars->map_vars.exit++;
			if (ft_strchr("CPE01", vars->map_vars.map[i][j]) == NULL)
			{
				printf("ERROR : none valide char in map file\n");
				return (false);
			}
			j++;
		}
		i++;
	}
	if (vars->map_vars.player != 1)
	{
		printf("ERROR : number of player\n");
		return (false);
	}
	if (vars->map_vars.collectible < 1)
	{
		printf("ERROR : no collectible\n");
		return (false);
	}
	if (vars->map_vars.exit != 1)
	{
		printf("ERROR : number of exit\n");
		return (false);
	}
	return (true);
}

bool	ft_check_param(int ac, char **av, t_vars *vars)
{	
	// check du nombre d'arguments
	if (!ft_invalid_arg_num(ac)) 
		return (false);

	// check du format .ber
	if (!ft_check_mapfile_format(av))	
		return (false);	
	
	// check du display de la map
	if(!ft_check_map(av, vars))
		return (false);	
		
	if(!ft_check_walls(vars))
		return(false);

	if (!ft_check_content(vars))
		return (false);
	
	return true;
}