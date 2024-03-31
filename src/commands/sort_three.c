/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:08:41 by lumaret           #+#    #+#             */
/*   Updated: 2024/03/31 16:36:43 by lumaret          ###   ########.fr       */
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
		t_stack_node *cheap_n)
{
	while (*b != cheap_n->target && *a != cheap_n)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}
