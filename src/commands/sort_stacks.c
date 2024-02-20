/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:44:46 by lumaret           #+#    #+#             */
/*   Updated: 2024/02/20 19:34:35 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
// stat rotate2
static void	rotate2(t_stack_node **a, t_stack_node **b, 
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

// stat rrotate2
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

// algo dans les graaaaandes lignes
void	turk_sort(t_stack_node **a, t_stack_node **b)
{
	int	lena;

	lena = stack_len(*a);
	//push 2 element de a dans b si lena > 3 sinon tri a 3
	if (lena-- > 3 && !is_sorted(*a))
		pb(a, b, false);
	if (lena-- > 3 && !is_sorted(*a))
		pb(a, b, false);
	while (lena-- > 3 && !is_sorted(*a))
	{
		init_node_a(*a, *b);
// push tous les elements de a vers b prealablement triee jusqua len_a=3
		move_a_2_b(a, b);
	}
	sort_three(a);
	while (*b != NULL)
	{
		init_node_b(*a, *b);
		move_b_2_a(a, b);
	}
	current_index(*a);
	put_top(a);
}
