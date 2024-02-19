/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:19:19 by lumaret           #+#    #+#             */
/*   Updated: 2024/02/15 05:59:59 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	syntaxe_error(char *str_n)
{
	if (!((*str_n == '+' || *str_n == '-')
			|| *str_n >= '0' && str_n <= '9'))
		return (1);
	if ((*str_n == '+' || *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	str_n++;
	while (*str_n)
	{
		if (!(str_n[1] >= '0' && str_n[1] <= '9'))
			return (1);
	}
	return (0);
}

int	doublons_error(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nb == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
/*		current->nb = 0; debug*/
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	print_error(t_stack_node **a)
{
	free_stack(a);
	ft_printf("ERROR :/\n");
	exit (1);
}