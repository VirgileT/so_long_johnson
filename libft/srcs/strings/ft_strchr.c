/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:56:40 by virgile           #+#    #+#             */
/*   Updated: 2023/01/25 11:53:01 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strchr(const char *s, int c)
// {
// 	char	t;

// 	if (!s)
// 		return (NULL);
// 	t = (char) c;
// 	while (*s != t && *s != '\0')
// 			s++;
// 	if (*s == t)
// 		return ((char *)s);
// 	return (NULL);
// }

char	*ft_strchr(const char *s, int c)
{
	char	f;

	if (!s)
		return (NULL);
	f = (char)c;
	while (*s && *s != f)
		s++;
	if (*s == f)
		return ((char *) s);
	return (NULL);
}