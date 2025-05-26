/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:22:42 by aychikhi          #+#    #+#             */
/*   Updated: 2025/05/26 09:44:22 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return ;
		i++;
	}
	error_mess();
}

void	convert_and_check(char *str)
{
	if ((ft_len(str) >= 10) && 
		((ft_atoi(str) > 2147483647) || (ft_atoi(str) < -2147483648)))
		error_mess();
}

int	counter(char *ptr)
{
	int	l;

	l = 0;
	while (*ptr)
	{
		while (ft_isspace(*ptr))
			ptr++;
		if ((*ptr == '+' || *ptr == '-') && *(ptr + 1) && ft_isdigit(*(ptr
					+ 1)))
			ptr++;
		if (ft_isdigit(*ptr))
		{
			l++;
			while (ft_isdigit(*ptr))
				ptr++;
			if (*ptr == '+' || *ptr == '-')
				error_mess();
		}
		else
			error_mess();
		while (ft_isspace(*ptr))
			ptr++;
	}
	return (l);
}
