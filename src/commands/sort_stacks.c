/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:44:46 by lumaret           #+#    #+#             */
/*   Updated: 2024/03/20 14:47:04 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate2(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rrotate2(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	move_a_2_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*thecheapest;

	thecheapest = the_cheapest(*a);
	if (thecheapest->above_med && thecheapest->target->above_med)
		rotate2(a, b, thecheapest);
	else if (!(thecheapest)->above_med && !(thecheapest)->target->above_med)
		rrotate2(a, b, thecheapest);
	for_each_push(a, thecheapest, 'a');
	for_each_push(b, thecheapest->target, 'b');
	pb(b, a, false);
}

static void	move_b_2_a(t_stack_node **a, t_stack_node **b)
{
	for_each_push(a, (*b)->target, 'a');
	pa(a, b, false);
}

//put top
static void	put_top(t_stack_node **a)
{
	while ((*a)->nb != min_o_stack(*a)->nb)
	{
		if (min_o_stack(*a)->above_med)
			ra(a, false);
		else
			rra(a, false);
	}
}
