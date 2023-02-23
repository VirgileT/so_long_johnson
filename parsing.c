/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:24:32 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/23 17:59:19 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

bool	ft_is_rectangle(t_vars *vars)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(vars->map_vars.map[0]);
	while (vars->map_vars.map[i] != NULL)
	{
		if (ft_strlen(vars->map_vars.map[i]) != len)
		{
			ft_error("Map shape is invalid");
			return (false);
		}
		i++;
		vars->map_vars.nb_of_rows++;
	}
	vars->map_vars.nb_of_cols = len;
	return (true);
}

bool	ft_check_map(char **av, t_vars *vars)
{
	int			map_fd;
	int			read_return;
	const int	read_s = (WIDTH_WINDOW / IMGSIZE + 1)
		* (HEIGHT_WINDOW / IMGSIZE + 1);
	char		*full;

	full = malloc(sizeof(char) * read_s);
	map_fd = open(av[1], O_RDONLY);
	if (map_fd == -1)
		return (ft_error("open() error !"), false);
	read_return = read(map_fd, full, read_s);
	if (read_return < 0)
		return (ft_error("read() error !"), false);
	if (read_return == read_s)
		return (ft_error("Map too big."), false);
	full[read_return] = '\0';
	if (!(ft_check_map2(full, read_return, vars)))
		return (false);
	vars->map_vars.map = ft_split(full, '\n');
	vars->map_vars.cloned_map = ft_split(full, '\n');
	free(full);
	if (!(ft_is_rectangle(vars)))
		return (false);
	return (true);
}

bool	ft_check_walls(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map_vars.map[0][i] != '\0')
	{
		if ((vars->map_vars.map[0][i] != '1')
			|| (vars->map_vars.map[vars->map_vars.nb_of_rows - 1][i] != '1'))
		{
			ft_error("Map must be surrounded by walls");
			return (false);
		}
		i++;
	}
	i = 0;
	while (vars->map_vars.map[i] != NULL)
	{
		if ((vars->map_vars.map[i][0] != '1')
			|| (vars->map_vars.map[i][vars->map_vars.nb_of_cols - 1] != '1'))
		{
			ft_error("Map must be surrounded by walls");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	ft_check_content(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map_vars.map[i] != NULL)
	{
		j = 0;
		while (vars->map_vars.map[i][j] != '\0')
		{
			if (ft_strchr("CPE01", vars->map_vars.map[i][j]) == NULL)
			{
				ft_error("None valide char in map file");
				ft_quit(vars);
			}
			j++;
		}
		i++;
	}
	ft_check_content2(vars);
	if (!ft_check_content3(vars))
		ft_quit(vars);
	return (true);
}

bool	ft_check_param(int ac, char **av, t_vars *vars)
{
	if (!ft_invalid_arg_num(ac))
		return (false);
	if (!ft_check_mapfile_format(av))
		return (false);
	if (!ft_check_map(av, vars))
		ft_quit(vars);
	if (!ft_check_walls(vars))
		ft_quit(vars);
	if (!ft_check_content(vars))
		return (false);
	return (true);
}
