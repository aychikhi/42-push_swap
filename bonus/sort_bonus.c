/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:01:11 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/27 12:29:23 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	error_mess(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

static void	free_fun(t_list **a, t_list **b, char *str)
{
	free(str);
	ft_lstclear(a);
	ft_lstclear(b);
	error_mess();
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

void	sort_fun(t_list **a, t_list **b, char *move)
{
	if (!ft_strcmp(move, "sa\n"))
		sa(a);
	else if (!ft_strcmp(move, "sb\n"))
		sb(b);
	else if (!ft_strcmp(move, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(move, "rb\n"))
		rb(b);
	else if (!ft_strcmp(move, "ra\n"))
		ra(a);
	else if (!ft_strcmp(move, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(move, "rra\n"))
		rra(a);
	else if (!ft_strcmp(move, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(move, "rrr\n"))
		rrr(a, b);
	else if (!ft_strcmp(move, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(move, "pb\n"))
		pb(b, a);
	else
		free_fun(a, b, move);
	free(move);
}

void	read_moves(t_list **a, t_list **b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		sort_fun(a, b, move);
		move = get_next_line(0);
	}
	free(move);
}
