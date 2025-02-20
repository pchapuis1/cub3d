/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:31:42 by pchapuis          #+#    #+#             */
/*   Updated: 2022/11/16 14:58:18 by pchapuis         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*max_range(void)
{
	char	*result;

	result = malloc(sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*result;
	size_t		x;
	size_t		max;

	if (!s)
		return (NULL);
	x = 0;
	max = ft_strlen(s);
	if (max < start)
		return (max_range());
	while (s[start + x])
		x ++;
	if (len > x)
		len = x;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	x = 0;
	while (x < len)
	{
		result[x] = s[start + x];
		x ++;
	}
	result[x] = '\0';
	return (result);
}
