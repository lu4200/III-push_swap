/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all _push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:36:44 by lumaret           #+#    #+#             */
/*   Updated: 2024/02/19 15:51:59 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **source)
{
	t_stack_node	*pushed;

	if (!source)
		return ;
	pushed = *source;
	*source = (*source)->next;
	pushed->prev = NULL;
	if (!*dest)
	{
		*dest = pushed;
		pushed->next = NULL;
	}
	else
	{
		pushed->next = *dest; // push devient le top o stack
		pushed->next->prev = pushed; // liaison bi-directionnelle
		*dest = pushed; // le haut de la stack pointe vers le noeud recemment ajoute
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}