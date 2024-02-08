/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:22:48 by lumaret           #+#    #+#             */
/*   Updated: 2024/02/08 20:06:02 by lumaret          ###   ########.fr       */
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

	struct	s_stack_node *next;
	struct	s_stack_node *prev;
	struct	s_stack_node *target
}	t_stack_node;

//Handle errors

//stack init

//nodes init

//stack utils

//commands

//alogrithms

#endif