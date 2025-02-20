/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:06:21 by pchapuis          #+#    #+#             */
/*   Updated: 2022/11/16 14:38:47 by pchapuis         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

static char	*empty(void)
{
	char	*result;

	result = malloc(sizeof(char));
	if (!result)
		return (NULL);
	result[0] = 0;
	return (result);
}

static char	*fill_trim(int start, int end, int i, char const *s1)
{
	char	*result;

	result = malloc(sizeof(char) * (end - start + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		result[i] = s1[start];
		start ++;
		i ++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (ft_inset(s1[i], set) == 1 && s1[i])
		i ++;
	start = i;
	while (s1[i])
		i ++;
	i = i - 1;
	while (ft_inset(s1[i], set) == 1 && i > 0)
		i --;
	end = i;
	if (end < start)
		return (empty());
	return (fill_trim(start, end, i, s1));
}
