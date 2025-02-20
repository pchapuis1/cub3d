/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:13:23 by pchapuis          #+#    #+#             */
/*   Updated: 2022/11/17 12:06:38 by pchapuis         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*data;

	if (!dst && !src)
		return (NULL);
	data = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		data[i] = ((unsigned char *)src)[i];
		i ++;
	}
	return (dst);
}
