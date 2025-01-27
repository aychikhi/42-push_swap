/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:48:37 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/27 18:24:41 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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

void	is_dup(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->n == tmp->n)
				error_mess();
			tmp = tmp->next;
		}
		lst = lst->next;
	}
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
