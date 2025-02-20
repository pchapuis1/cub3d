/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:35:54 by pchapuis          #+#    #+#             */
/*   Updated: 2022/11/16 14:57:06 by pchapuis         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (dstsize == 0)
		return (ft_strlen(src));
	j = 0;
	while (dst[j] && j < dstsize)
		j ++;
	i = 0;
	while (src[i] && dstsize && j + i < dstsize - 1)
	{
		dst[i + j] = src[i];
		i ++;
	}
	if (j < dstsize)
		dst[i + j] = '\0';
	i = 0;
	while (src[i])
		i ++;
	return (i + j);
}
