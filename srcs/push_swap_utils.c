/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:18:36 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/25 11:41:27 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	error_mess(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	is_dup(int num, t_list *lst)
{
	while (lst)
	{
		if (num == lst->n)
			error_mess();
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
