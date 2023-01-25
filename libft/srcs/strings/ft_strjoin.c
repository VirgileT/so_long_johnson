/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:21:05 by virgile           #+#    #+#             */
/*   Updated: 2023/01/25 11:52:33 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*dst;
// 	size_t	i;
// 	size_t	len1;
// 	size_t	len2;

// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	dst = (char *)malloc((len1 + len2) * sizeof(char) + 1);
// 	i = 0;
// 	if (!(dst))
// 		return (NULL);
// 	while (*s1)
// 		dst[i++] = *s1++;
// 	while (*s2)
// 		dst[i++] = *s2++;
// 	dst[i] = '\0';
// 	return (dst);
// }

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	dst_size;
	char	*dst;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	dst_size = ft_strlen(s1) + ft_strlen(s2);
	dst = malloc((dst_size + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (*s1)
		dst[i++] = *s1++;
	while (*s2)
		dst[i++] = *s2++;
	dst[i] = '\0';
	return (dst);
}