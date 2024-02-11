/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:06:50 by lumaret           #+#    #+#             */
/*   Updated: 2024/02/11 01:21:53 by lumaret          ###   ########.fr       */
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
