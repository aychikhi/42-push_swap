/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:53:30 by aychikhi          #+#    #+#             */
/*   Updated: 2025/05/26 09:44:08 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list **a)
{
	rrotate(a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **b)
{
	rrotate(b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **a, t_list **b)
{
	rrotate(a);
	rrotate(b);
	ft_putendl_fd("rrr", 1);
}
