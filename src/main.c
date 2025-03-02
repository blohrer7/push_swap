/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:33:41 by blohrer           #+#    #+#             */
/*   Updated: 2025/03/02 23:44:47 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		parse_arguments(argc, argv, &stack_a);
		if (is_sorted(stack_a))
		{
			clear(&stack_a, &stack_b);
			return (0);
		}
		sort_stack(&stack_a, &stack_b);
	}
	clear(&stack_a, &stack_b);
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	t_node	*stack_a;
// 	t_node	*stack_b;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	if (argc > 1)
// 	{
// 		parse_arguments(argc, argv, &stack_a);
// 		if (is_sorted(stack_a))
// 		{
// 			printf("Stack ist bereits sortiert.\n");
// 			print_stack(stack_a);
// 			clear(&stack_a, &stack_b);
// 			return (0);
// 		}
// 		sort_stack(&stack_a, &stack_b);
// 	}
// 	printf("Fertig sortierter Stack:\n");
// 	print_stack(stack_a); // Stack nach der Sortierung ausgeben
// 	clear(&stack_a, &stack_b);
// 	return (0);
// }
