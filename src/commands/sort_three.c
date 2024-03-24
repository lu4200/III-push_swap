/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:08:41 by lumaret           #+#    #+#             */
/*   Updated: 2024/03/24 14:05:02 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest;

	biggest = max_o_stack(*a);
	if (biggest == *a)
		ra(a, false);
	else if ((*a)->next == biggest)
		rra(a, false);
	if ((*a)->nb > (*a)->next->nb)
		sa(a, false);
}

void	rrotate2(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}