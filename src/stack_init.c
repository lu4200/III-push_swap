/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:48:20 by lumaret           #+#    #+#             */
/*   Updated: 2024/02/15 06:01:45 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long	ft_atol(const char *s)
{
	long	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n'
		|| *s == '\r' || *s == '\f' || *s == '\v')
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (ft_isdigit(*s))
		res = res * 10 + (*s++ - '0');
	return (res * sign);
}

static void	add_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node)); //new node
	if (!node)
		return ;
	node->next = NULL; // first node so nxt = NULL
	node->nb = n;	//assgin value to node
	if (!(*stack))
	{
		*stack = node; // if no stack, 1st element = node
		node->prev = NULL; // set prev NULL X -> data -> X
	}
	else
	{
		last_node = point_on_last(*stack); // point on the last
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			print_error(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			print_error(a);
		if (error_duplicate(*a, (int)n))
			print_error(a);
		add_node(a, (int)n);
		i++;
	}
}

t_stack_node *the_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	for_each_push(t_stack_node **stack, t_stack_node *top_node, char name)
{
	while (*stack != top_node) 
	{
		if (name == 'a') 
		{
			if (top_node->above_med)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_med)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}
