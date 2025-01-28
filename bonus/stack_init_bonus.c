/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:20:32 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/28 13:43:02 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	is_sorted(t_list **a, t_list **b)
{
	int		size;
	int		i;
	t_list	*tmp;

	tmp = *a;
	i = 0;
	size = ft_lstsize(*a);
	if (ft_lstsize(*b))
		return (0);
	while (size - 1 >= i)
	{
		if (tmp->index != i)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

static void	free2(t_list **a, t_list **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
}

static void	check_is_sorted(t_list **a, t_list **b)
{
	if (!is_sorted(a, b))
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
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

void	set_up(char **str)
{
	t_list	*stack[2];
	int		i;

	i = 0;
	stack[0] = NULL;
	stack[1] = NULL;
	while (str[i])
	{
		convert_and_check(str[i]);
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
	read_moves(&stack[0], &stack[1]);
	check_is_sorted(&stack[0], &stack[1]);
	free2(&stack[0], &stack[1]);
}
