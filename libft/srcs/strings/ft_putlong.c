/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:33:26 by vtestut           #+#    #+#             */
/*   Updated: 2022/12/07 17:51:50 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlong(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putlong(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
}
