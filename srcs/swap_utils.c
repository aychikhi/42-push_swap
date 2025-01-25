/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:34:23 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/25 11:11:12 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	sa(t_list **a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_list **b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}
