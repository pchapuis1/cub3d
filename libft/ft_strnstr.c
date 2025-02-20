/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:35:27 by pchapuis          #+#    #+#             */
/*   Updated: 2022/11/16 14:39:36 by pchapuis         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	int		x;

	if (!haystack && !len)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	x = ft_strlen(needle);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && i + j < len)
			{
				j ++;
				if (j == x)
					return ((char *)haystack + i);
			}
		}
		i ++;
	}
	return (NULL);
}
