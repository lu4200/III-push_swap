/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:45:52 by lumaret           #+#    #+#             */
/*   Updated: 2024/03/31 17:08:15 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	char			**argv2;
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	argv2 = argv;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv2 = ps_split(argv[1], ' '); // segfault ./push_swap "            ";
	init_stack_a(&a, argv2 + 1);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			turk_sort(&a, &b);
	}
	if (argc == 2)
		leak(argv2);
	free_stack(&a);
	return (0);
}
/*
 =========================== PARSING ================================
	
 - faire attention au doublons avec le double cote
 - faire attention au segfault de ./push_swap "abcd" et de ./push_swap "     "
 - ./push_swap "" est un argument non valide donc retour "Erro :/"
 - faire attention au segfault quand tu as qu'un seul arguments valide !
 - Revoir l overflow du long long ! Renvoyer erreur par exemple : ./push_swap 9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999 8 7 6 5 4 

========================== ALGO =====================================

OK !

*/