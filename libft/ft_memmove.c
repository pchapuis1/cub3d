/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:20:05 by pchapuis          #+#    #+#             */
/*   Updated: 2022/11/16 14:28:41 by pchapuis         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*data;

	if (!dst && !src)
		return (NULL);
	if (dst < src)
		return (ft_memcpy (dst, src, len));
	data = (unsigned char *)dst;
	while (len -- > 0)
	{
		data[len] = ((unsigned char *)src)[len];
	}
	return (dst);
}
