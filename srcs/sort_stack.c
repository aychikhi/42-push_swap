/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:20:20 by aychikhi          #+#    #+#             */
/*   Updated: 2025/05/26 09:44:10 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_pos(t_list *lst, int n)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!lst)
		return (0);
	tmp = lst;
	while (tmp)
	{
		if (tmp->index != n)
			tmp = tmp->next;
		else
			break ;
		i++;
	}
	return (i);
}

void	sort_stack(t_list **a, t_list **b)
{
	int		min;
	double	max;
	int		size;

	size = ft_lstsize(*a);
	max = 0.05 * size + 10.0;
	min = 0;
	while (*a)
	{
		if (min <= (*a)->index && (*a)->index <= max)
		{
			pb(b, a);
			min++;
			max++;
		}
		else if ((*a)->index < min)
		{
			pb(b, a);
			rb(b);
			min++;
			max++;
		}
		else
			ra(a);
	}
}

void	rsort_stack(t_list **a, t_list **b)
{
	int	size;
	int	max;

	if (is_sorted(a, b))
		return ;
	sort_stack(a, b);
	while (*b)
	{
		size = ft_lstsize(*b);
		max = ft_lstsize(*b) - 1;
		if ((*b)->index == max)
			pa(a, b);
		else if (get_pos(*b, max) < size / 2)
			rb(b);
		else
			rrb(b);
	}
}
