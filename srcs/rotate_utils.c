/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:46:55 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/22 11:53:12 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ra(t_list **a)
{
	rotate(a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_list **b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
