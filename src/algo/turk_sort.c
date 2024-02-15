/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:44:46 by lumaret           #+#    #+#             */
/*   Updated: 2024/02/15 06:05:17 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
// stat rotate2
// stat rrotate2
//move_a_2_b
//move_b_2_a
//put top


// algo dans les graaaaandes lignes
void	turk_sort(t_stack_node **a, t_stack_node **b)
{
	int	lena;

	lena = stack_len(a);
	//push 2 element de a dans b si lena > 3 sinon tri a 3
	if (lena-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	if (lena-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	while (lena-- > 3 && !is_sorted)
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
