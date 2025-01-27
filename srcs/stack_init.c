/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:25:54 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/27 12:20:30 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	check(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 5 || ft_lstsize(*a) == 4)
		five(a, b);
	if (ft_lstsize(*a) == 3)
		tree(a);
	else if (ft_lstsize(*a) == 2)
		two(a);
	else if (ft_lstsize(*a) == 1)
		return ;
	else
		rsort_stack(a, b);
}

int	is_sorted(t_list **a)
{
	int		size;
	int		i;
	t_list	*tmp;

	tmp = *a;
	i = 0;
	size = ft_lstsize(*a);
	while (size - 1 >= i)
	{
		if (tmp->index != i)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

void	set_up(char **str)
{
	t_list	*stack[2];
	int		i;

	i = 0;
	stack[0] = NULL;
	stack[1] = NULL;
	while (str[i])
	{
		if (!stack[0] && !stack[1])
		{
			stack[0] = ft_lstnew(ft_atoi(str[i]));
			stack[1] = NULL;
		}
		else
			ft_lstadd_back(&stack[0], ft_lstnew(ft_atoi(str[i])));
		i++;
	}
	is_dup(stack[0]);
	get_index(stack[0]);
	check(&stack[0], &stack[1]);
	ft_lstclear(&stack[0]);
	ft_lstclear(&stack[1]);
}
