/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:29:48 by pchapuis          #+#    #+#             */
/*   Updated: 2023/11/22 15:52:54 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*first_word(char *str)
{
	char	*word;
	int		i;
	int		start;
	int		size;

	i = 0;
	while (str[i] && str[i] == ' ')
		i ++;
	start = i;
	while (str[i] && str[i] != ' ')
		i ++;
	size = i - start;
	word = malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] == ' ')
		i ++;
	while (str[i] && str[i] != ' ')
	{
		word[i - start] = str[i];
		i ++;
	}
	word[i - start] = '\0';
	return (word);
}

char	*last_word(char *str)
{
	int		i;
	int		start;
	int		size;
	int		j;
	char	*word;

	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] == ' ')
		i --;
	start = i;
	while (i >= 0 && str[i] != ' ')
		i --;
	size = start - i;
	word = malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	i ++;
	j = 0;
	while (str[i + j] && str[i + j] != ' ')
	{
		word[j] = str[i + j];
		j ++;
	}
	word[j] = '\0';
	return (word);
}

int	count_word(char *str)
{
	int	tot;
	int	i;
	int	status;

	tot = 0;
	i = 0;
	status = 0;
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			status = 0;
		if (str[i] != ' ' && (str[i] < 9 || str[i] > 13))
		{
			if (status == 0)
				tot ++;
			status = 1;
		}
		i ++;
	}
	return (tot);
}
