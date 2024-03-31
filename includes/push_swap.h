/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:22:48 by lumaret           #+#    #+#             */
/*   Updated: 2024/03/31 16:56:59 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

t_stack_node					*the_cheapest(t_stack_node *stack);
t_stack_node					*point_on_last(t_stack_node *stack);
t_stack_node					*max_o_stack(t_stack_node *stack);
t_stack_node					*min_o_stack(t_stack_node *stack);

typedef struct s_stack_node
{
	bool				cheapest;
	bool				above_med;
	int					push_cost;
	int					nb;
	int					index;

	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}	t_stack_node;

void							print_error(t_stack_node **a);
void							free_stack(t_stack_node **stack);
void							init_stack_a(t_stack_node **a, char **argv);
void							current_index(t_stack_node *stack);
void							set_cheapest(t_stack_node *stack);
void							init_node_a(t_stack_node *a, t_stack_node *b);
void							init_node_b(t_stack_node *a, t_stack_node *b);
bool							is_sorted(t_stack_node *stack);
char							**ps_split(char *s, char c);
void							print_stack(t_stack_node *a, t_stack_node *b);
void							sort_three(t_stack_node **a);
void							turk_sort(t_stack_node **a, t_stack_node **b);
void							sa(t_stack_node **a, bool print);
void							sb(t_stack_node **b, bool print);
void							ra(t_stack_node **a, bool print);
void							rb(t_stack_node **b, bool print);
void							rra(t_stack_node **a, bool print);
void							rrb(t_stack_node **b, bool print);
char							**free_array(char **array);
void							*leak(char **splitted);
int								stack_len(t_stack_node	*stack);
int								syntaxe_error(char *str_n);
int								doublons_error(t_stack_node *a, int n);
void							ss(t_stack_node **a, t_stack_node **b, bool p);
void							rrr(t_stack_node **a, t_stack_node **b, bool p);
void							pa(t_stack_node **a, t_stack_node **b, bool p);
void							pb(t_stack_node **a, t_stack_node **b, bool p);
void							rrotate2(t_stack_node **a, t_stack_node **b, t_stack_node *cheap_n);
void							for_each_push(t_stack_node **stack, t_stack_node *top_n, char name);

#endif