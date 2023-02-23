/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:00:41 by vtestut           #+#    #+#             */
/*   Updated: 2023/02/23 15:41:30 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_error(char *str)
{
	ft_printf("Error\n%s\n", str);
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
		ft_error("mauvais format de fichier");
		return (false);
	}
	else
		return (true);
}
