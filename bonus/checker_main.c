/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:03:49 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/28 13:09:03 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	join_arg2(char **arg, char **str, int i)
{
	int	j;

	j = 0;
	while (str[j])
	{
		arg[i] = str[j];
		i++;
		j++;
	}
	return (j);
}

static char	**join_arg(char **arg, char **src)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 1;
	while (src[j])
	{
		if (check_space(src[j]))
		{
			split = ft_split(src[j], ' ');
			i += join_arg2(arg, split, i);
			free(split);
		}
		else
		{
			arg[i] = src[j];
			i++;
		}
		j++;
	}
	return (arg);
}

int	main(int ac, char **av)
{
	int		i;
	char	**str;
	int		l;

	if (ac == 1)
		return (0);
	i = 0;
	l = 0;
	while (i++ < ac - 1)
	{
		if (!av[i][0])
			error_mess();
		is_empty(av[i]);
		l += counter(av[i]);
	}
	str = malloc((l + 1) * sizeof(char *));
	if (!str)
		return (0);
	str[l] = NULL;
	join_arg(str, av);
	set_up(str);
	free(str);
	return (0);
}
