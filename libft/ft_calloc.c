/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:01:16 by pchapuis          #+#    #+#             */
/*   Updated: 2022/11/18 11:59:47 by pchapuis         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (count && size > SIZE_MAX / count)
		return (NULL);
	result = malloc(size * count);
	if (!result)
		return (NULL);
	ft_bzero(result, count * size);
	return (result);
}
