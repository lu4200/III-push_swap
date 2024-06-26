/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:45:52 by lumaret           #+#    #+#             */
/*   Updated: 2024/04/04 21:36:39 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	parsing(t_stack_node **a, int argc, char **argv)
{
	char			**argv2;

	argv2 = argv;
	if (argc < 2)
		exit (1);
	else if (argc == 2)
	{
		argv2 = ps_split(argv[1], ' ');
		if (!argv2)
			exit (1);
	}
	if (argc == 2)
	{
		init_stack_a(a, argv2 + 1, argv2);
		leak(argv2);
	}
	else
		init_stack_a(a, argv2 + 1, NULL);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	parsing(&a, argc, argv);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			turk_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}

int	ft_strlenw0(const char *s)
{
	int	i;
	int	index;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] == '0')
		i++;
	index = 0;
	while (s[index])
		index++;
	return (index - i);
}