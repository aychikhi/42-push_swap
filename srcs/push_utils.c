/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:42:02 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/23 13:36:30 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	ft_putendl_fd("pa", 1);
}

void	pb(t_list **b, t_list **a)
{
	push(b, a);
	ft_putendl_fd("pb", 1);
}
