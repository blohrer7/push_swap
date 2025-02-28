/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:40:21 by blohrer           #+#    #+#             */
/*   Updated: 2025/02/28 09:19:50 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_stack(t_node **stack, const char *operation)
{
	t_node	*first;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	ft_node_add_back(stack, first);
	ft_printf("%s\n", operation);
}

void	rotate_a(t_node **stack_a)
{
	rotate_stack(stack_a, "ra");
}

void	rotate_b(t_node **stack_b)
{
	rotate_stack(stack_b, "rb");
}

void	rotate_both(t_node **stack_a, t_node **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_printf("rr\n");
}
