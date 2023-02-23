/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:51 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/23 15:05:20 by vtestut          ###   ########.fr       */
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

bool	ft_check_map2(char *full, int read_return)
{
	int	i;

	i = 0;
	while (full[i] != '\0')
	{
		if (full[0] == '\n')
		{
			free(full);
			return (ft_error("empty line at begining of map file"), false);
		}
		else if (full[i] == '\n' && full[i + 1] == '\n')
		{	
			free(full);
			return (ft_error("empty line in middle of map file"), false);
		}
		else if (full[read_return - 1] == '\n')
		{
			free(full);
			return (ft_error("empty line at end of map file"), false);
		}
		i++;
	}
	return (true);
}
