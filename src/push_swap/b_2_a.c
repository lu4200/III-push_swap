/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_2_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:37:57 by lumaret           #+#    #+#             */
/*   Updated: 2024/02/20 21:41:16 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	long			best;

	while (b)
	{
		best = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nb > b->nb && current_a->nb < best)
			{
				best = current_a->nb;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best == LONG_MAX)
			b->target = target;
		b = b->next;
	}
}

void	init_node_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}