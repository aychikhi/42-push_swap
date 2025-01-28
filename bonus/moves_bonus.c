/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:35:32 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/27 12:28:32 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	swap(t_list **lst)
{
	t_list	*tmp;

	tmp = NULL;
	if (lst && *lst && (*lst)->next)
	{
		tmp = (*lst)->next;
		(*lst)->next = tmp->next;
		tmp->next = *lst;
		*lst = tmp;
	}
}

void	rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;

	tmp = NULL;
	last = NULL;
	if (lst && *lst && (*lst)->next)
	{
		tmp = (*lst)->next;
		last = ft_lstlast(*lst);
		last->next = *lst;
		(*lst)->next = NULL;
		*lst = tmp;
	}
}

void	rrotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*before_last;

	tmp = NULL;
	last = NULL;
	before_last = NULL;
	if (lst && *lst && (*lst)->next)
	{
		tmp = *lst;
		while (tmp && tmp->next)
		{
			if (!tmp->next->next)
				before_last = tmp;
			tmp = tmp->next;
		}
		last = ft_lstlast(*lst);
		last->next = *lst;
		*lst = last;
		before_last->next = NULL;
	}
}

void	push(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	tmp = NULL;
	printf("1-> %ld\n", (*lst_a)->n);
	if (lst_b && *lst_b)
	{
		if (!*lst_a)
		{
			tmp = (*lst_b)->next;
			*lst_a = *lst_b;
			(*lst_a)->next = NULL;
			*lst_b = tmp;
		}
		else
		{
			tmp = (*lst_b)->next;
			(*lst_b)->next = *lst_a;
			*lst_a = *lst_b;
			*lst_b = tmp;
		}
	}
	printf("2-> %ld\n", (*lst_a)->n);
}
