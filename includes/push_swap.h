/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:22:48 by lumaret           #+#    #+#             */
/*   Updated: 2024/02/13 19:03:34 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../includes/libft/libft.h"
# include "../includes/ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int		nb;
	int		index;
	int		push_cost;
	bool		above_med;
	bool		cheapest;

	struct	s_stack_node	*next;
	struct	s_stack_node	*prev;
	struct	s_stack_node	*target;
}	t_stack_node;

//Handle errors
int	syntaxe_error(char *str_n);
int	doublons_error(t_stack_node *a, int n);
void	free_stack(t_stack_node **stack);
void	print_error(t_stack_node **a);

//stack init
void	init_stack_a(t_stack_node **a, char **argv);
t_stack_node *the_cheapest(t_stack_node *stack);
void	for_each_push(t_stack_node **stack, t_stack_node *top_node, char name);

//nodes init
void	init_node_a(t_stack_node *a, t_stack_node *b);
void	init_node_b(t_stack_node *a, t_stack_node *b);

//stack utils
t_stack_node	*min_o_stack(t_stack_node *stack);
t_stack_node		*point_on_last(t_stack_node *stack);
int			stack_len(t_stack_node *stack);
t_stack_node		*max_o_stack(t_stack_node *stack);
char			**ps_split(char *s, char c);
bool	is_sorted(t_stack_node *stack);

//commands
t_stack_node	sa(t_stack_node **a, bool print);
t_stack_node	sb(t_stack_node **b, bool print);
t_stack_node	ss(t_stack_node **a, t_stack_node **b, bool print);

void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);


//alogrithms
void	sort_three(t_stack_node **a);
void	turk_sort(t_stack_node **a, t_stack_node **b);

void	current_index(t_stack_node *stack);
void	set_cheapest(t_stack_node *stack);
#endif