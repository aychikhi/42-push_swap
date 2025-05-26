/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:18:36 by aychikhi          #+#    #+#             */
/*   Updated: 2025/05/26 09:44:01 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
