/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:39:39 by pchapuis          #+#    #+#             */
/*   Updated: 2022/11/16 15:05:24 by pchapuis         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lengh(int n)
{
	int				len;
	unsigned int	nb;

	len = 0;
	if (n < 0)
	{
		len ++;
		nb = -n;
	}
	else
		nb = n;
	while (nb > 9)
	{
		nb = nb / 10;
		len ++;
	}
	return (len + 1);
}

static void	place(char *result, unsigned int nb, int len)
{
	result[len] = '\0';
	len --;
	while (nb > 9)
	{
		result[len] = (nb % 10) + 48;
		nb /= 10;
		len --;
	}
	result[len] = nb + 48;
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	nb;
	int				i;

	result = malloc(sizeof(char) * (lengh(n) + 1));
	if (!result)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		result[i] = '-';
		nb = -n;
		i ++;
	}
	else
		nb = n;
	place(result, nb, lengh(n));
	return (result);
}
