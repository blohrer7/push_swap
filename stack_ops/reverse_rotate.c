/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:42:34 by blohrer           #+#    #+#             */
/*   Updated: 2025/02/28 09:19:46 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_stack(t_node **stack, const char *operation)
{
	t_node	*prev;
	t_node	*current;

	prev = NULL;
	current = *stack;
	if (!stack || !*stack || !(*stack)->next)
		return ;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *stack;
	*stack = current;
	ft_printf("%s\n", operation);
}

void	reverse_rotate_a(t_node **stack_a)
{
	reverse_rotate_stack(stack_a, "rra");
}

void	reverse_rotate_b(t_node **stack_b)
{
	reverse_rotate_stack(stack_b, "rrb");
}

void	reverse_rotate_both(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_printf("rrr\n");
}
