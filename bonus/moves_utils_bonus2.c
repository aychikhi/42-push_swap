/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils_bonus2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:37:41 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/26 20:11:32 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	rra(t_list **a)
{
	rrotate(a);
}

void	rrb(t_list **b)
{
	rrotate(b);
}

void	rrr(t_list **a, t_list **b)
{
	rrotate(a);
	rrotate(b);
}
