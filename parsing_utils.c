/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:51 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/23 18:29:51 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

bool	ft_check_content3(t_vars *vars)
{
	if (vars->map_vars.player != 1)
		return (ft_error("No player"), false);
	if (vars->map_vars.collectible < 1)
		return (ft_error("No collectible"), false);
	if (vars->map_vars.exit != 1)
		return (ft_error("No exit"), false);
	return (true);
}

void	ft_check_content2(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map_vars.map[i] != NULL)
	{
		j = 0;
		while (vars->map_vars.map[i][j] != '\0')
		{
			if (vars->map_vars.map[i][j] == 'P')
			{
				vars->map_vars.player++;
				vars->y_hero = i;
				vars->x_hero = j;
			}
			else if (vars->map_vars.map[i][j] == 'C')
				vars->map_vars.collectible++;
			else if (vars->map_vars.map[i][j] == 'E')
				vars->map_vars.exit++;
			j++;
		}
		i++;
	}
}

bool	ft_check_map2(char *full, int read_return, t_vars *vars)
{
	int	i;

	i = 0;
	while (full[i] != '\0')
	{
		if (full[0] == '\n')
		{
			ft_error("empty line at begining of map file");
			ft_quit_early(vars, full);
		}
		else if (full[i] == '\n' && full[i + 1] == '\n')
		{	
			ft_error("empty line in middle of map file");
			ft_quit_early(vars, full);
		}
		else if (full[read_return - 1] == '\n')
		{
			ft_error("empty line at end of map file");
			ft_quit_early(vars, full);
		}
		i++;
	}
	return (true);
}

bool	ft_invalid_arg_num(int ac)
{
	if (ac > 2)
	{
		ft_error("too many arguments");
		return (false);
	}
	else if (ac < 2)
	{
		ft_error("argument missing");
		return (false);
	}
	else
		return (true);
}

bool	ft_check_mapfile_format(char **av)
{
	int	map_file_len;

	map_file_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][map_file_len - 4], ".ber", 4))
	{
		ft_error("Wrong map file format : [.ber] file is required");
		return (false);
	}
	else
		return (true);
}
