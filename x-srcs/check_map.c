/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:37:44 by vtestut           #+#    #+#             */
/*   Updated: 2023/01/25 18:53:08 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


/* checker que le fichier soit en .ber
** checker que le fichier existe
** checker que le fichier soit readable
** check que ce soit un rectangle
** check que ce soit entourre par des walls
** check que la map soit "terinable"
** check les collectibles / exit point / player */


int check_map()
{
	if map_exist() == 0
    if check_format() == 0
	if check_readable() == 0
	if check_shape() == 0
	if check_walls() == 0
	if check_map_args() == 0
}