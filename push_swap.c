/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:38:32 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/25 16:09:50 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == '-' || str[i] == '+'))
		{
			if (str[i + 1] && ft_isdigit(str[i + 1]) == 0)
				error_mess();
			i++;
		}
		if (ft_isdigit(str[i]) == 0)
			error_mess();
		i++;
	}
	return (1);
}

static void	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 32)
			return ;
		i++;
	}
	error_mess();
}

static void	convert_and_check(char **str)
{
	int	i;

	i = 0;
	while (str[i] && check(str[i]) == 1)
		i++;
	i = 0;
	while (str[i])
	{
		if ((ft_strlen(str[i]) >= 10) && ((ft_atoi(str[i]) > 2147483647)
				|| (ft_atoi(str[i]) < -2147483648)))
			error_mess();
		i++;
	}
}

static void	free_fun(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	main(int ac, char **av)
{
	int		i;
	char	**str;
	char	*ptr;

	i = 0;
	if (ac == 1)
		return (0);
	while (i++ < ac - 1)
	{
		is_empty(av[i]);
		if (!av[i][0])
			error_mess();
		ptr = ft_strjoin(ptr, av[i]);
		ptr = ft_strjoin(ptr, " ");
	}
	str = ft_split(ptr, ' ');
	free(ptr);
	convert_and_check(str);
	set_up(str);
	free_fun(str);
	return (0);
}
