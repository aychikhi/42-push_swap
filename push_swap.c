/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:38:32 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/27 12:51:27 by aychikhi         ###   ########.fr       */
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
		if ((ft_len(str[i]) >= 10) && ((ft_atoi(str[i]) > 2147483647)
				|| (ft_atoi(str[i]) < -2147483648)))
			error_mess();
		i++;
	}
}

static char	**join_arg(char **arg, char **src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		arg[i] = src[i + 1];
		i++;
	}
	arg[i] = NULL;
	return (arg);
}

int	main(int ac, char **av)
{
	int		i;
	char	**str;
	int		l;

	if (ac == 1)
		return (0);
	i = -1;
	l = 0;
	while (i++ < ac - 1)
	{
		is_empty(av[i]);
		if (!av[i][0])
			error_mess();
		if (check_space(av[i]))
			l += count_word2(av[i]);
	}
	l += ac - 1;
	str = malloc(sizeof(char *) * ac);
	join_arg(str, av);
	convert_and_check(str);
	set_up(str);
	free(str);
	return (0);
}
