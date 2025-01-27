/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:22:42 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/27 12:29:50 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	count_word2(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		if (str[i])
			c++;
		while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			i++;
	}
	return (c);
}

int	check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 32)
			return (1);
		i++;
	}
	return (0);
}
