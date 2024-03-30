/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:22:48 by lumaret           #+#    #+#             */
/*   Updated: 2024/03/30 19:02:14 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

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

void		print_error(t_stack_node **a);
void		free_stack(t_stack_node **stack);
int			syntaxe_error(char *str_n);
int			doublons_error(t_stack_node *a, int n);
void		init_stack_a(t_stack_node **a, char **argv);
void		current_index(t_stack_node *stack);
void		for_each_push(t_stack_node **stack, t_stack_node *top_node, char name);
void		set_cheapest(t_stack_node *stack);
void		init_node_a(t_stack_node *a, t_stack_node *b);
void		init_node_b(t_stack_node *a, t_stack_node *b);
int			stack_len(t_stack_node *stack);
bool		is_sorted(t_stack_node *stack);
char		**ps_split(char *s, char c);
void		print_stack(t_stack_node *a, t_stack_node *b);
void		sort_three(t_stack_node **a);
void		turk_sort(t_stack_node **a, t_stack_node **b);
t_stack_node	*the_cheapest(t_stack_node *stack);
t_stack_node	*point_on_last(t_stack_node *stack);
t_stack_node	*max_o_stack(t_stack_node *stack);
t_stack_node	*min_o_stack(t_stack_node *stack);
void		sa(t_stack_node **a, bool print);
void		sb(t_stack_node **b, bool print);
void		ss(t_stack_node **a, t_stack_node **b, bool print);
void		ra(t_stack_node **a, bool print);
void		rb(t_stack_node **b, bool print);
void		rr(t_stack_node **a, t_stack_node **b, bool print);
void		rra(t_stack_node **a, bool print);
void		rrb(t_stack_node **b, bool print);
void		rrr(t_stack_node **a, t_stack_node **b, bool print);
void		pa(t_stack_node **a, t_stack_node **b, bool print);
void		pb(t_stack_node **a, t_stack_node **b, bool print);
void		rrotate2(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
char	**free_array(char **array);
void	*leak(char **splitted);

#endif