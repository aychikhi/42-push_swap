/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:35:03 by aychikhi          #+#    #+#             */
/*   Updated: 2025/05/26 09:44:12 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	small_pos(t_list *a, int flag)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->index == 0 && flag == 0)
			return (i);
		if (a->index == 1 && flag == 1)
			return (i);
		a = a->next;
		i++;
	}
	return (i);
}

void	five(t_list **a, t_list **b)
{
	int	size;
	int	flag;

	size = ft_lstsize(*a) / 2;
	flag = 0;
	if (is_sorted(a, b))
		return ;
	if (ft_lstsize(*a) == 5)
	{
		while (size && small_pos(*a, flag))
		{
			if (size >= small_pos(*a, flag))
				ra(a);
			else
				rra(a);
			size--;
		}
		if (is_sorted(a, b))
			return ;
		pb(b, a);
		flag = 1;
	}
	four(a, b, flag);
	if (flag)
		pa(a, b);
}

void	four(t_list **a, t_list **b, int flag)
{
	int	size;

	size = ft_lstsize(*a) / 2;
	if (ft_lstsize(*a) == 4)
	{
		size = ft_lstsize(*a) / 2;
		while (size && small_pos(*a, flag))
		{
			if (size >= small_pos(*a, flag))
				ra(a);
			else
				rra(a);
			size--;
		}
		if (is_sorted(a, b))
			return ;
		pb(b, a);
		tree(a);
		pa(a, b);
	}
}

void	tree(t_list **a)
{
	if (((*a)->index < (*a)->next->index
			&& (*a)->index < (*a)->next->next->index)
		&& (*a)->next->index < (*a)->next->next->index)
		return ;
	if ((*a)->index < (*a)->next->index
		&& (*a)->index < (*a)->next->next->index)
		rra(a);
	if ((*a)->index > (*a)->next->index
		&& (*a)->index > (*a)->next->next->index)
		ra(a);
	if ((*a)->index > (*a)->next->index
		&& (*a)->index < (*a)->next->next->index)
		sa(a);
	if ((*a)->index < (*a)->next->index
		&& (*a)->index > (*a)->next->next->index)
		rra(a);
}

void	two(t_list **a)
{
	if ((*a)->index == 1)
		sa(a);
	return ;
}
