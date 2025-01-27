/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:18:36 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/27 12:27:47 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	error_mess(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

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

void	get_index(t_list *lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (lst && lst->next)
	{
		tmp1 = lst;
		while (tmp1)
		{
			tmp1->index = 0;
			tmp1 = tmp1->next;
		}
		tmp1 = lst;
		while (tmp1)
		{
			tmp2 = lst;
			while (tmp2)
			{
				if (tmp1->n > tmp2->n)
					tmp1->index++;
				tmp2 = tmp2->next;
			}
			tmp1 = tmp1->next;
		}
	}
}
