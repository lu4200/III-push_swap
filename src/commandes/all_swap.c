/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:06:50 by lumaret           #+#    #+#             */
/*   Updated: 2024/02/11 02:31:49 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_stack_node **head)
{
	t_stack_node	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	(*head)->prev = temp;
	if (temp->next != NULL)
		temp->next->prev = *head;
	temp->next = *head;
	temp->prev = NULL;
	*head = temp;
}

t_stack_node	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

t_stack_node	sa(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

t_stack_node	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}