/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:58:16 by blohrer           #+#    #+#             */
/*   Updated: 2025/03/02 16:25:54 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	position_in_b(t_node **stack_b, t_node *cheapest)
{
	while (*stack_b != cheapest)
	{
		if (cheapest->index <= ft_node_size(*stack_b) / 2)
			rotate_b(stack_b);
		else
			reverse_rotate_b(stack_b);
	}
}

void	position_in_a(t_node **stack_a, t_node *cheapest)
{
	while (*stack_a != cheapest->target)
	{
		if (cheapest->target->index <= ft_node_size(*stack_a) / 2)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
}

void	move_back(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;

	cheapest = get_lowest_cost(*stack_b);
	position_in_b(stack_b, cheapest);
	position_in_a(stack_a, cheapest);
	push_a(stack_a, stack_b);
}

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a || !*stack_a)
		return ;
	while (ft_node_size(*stack_a) > 3)
		push_b(stack_b, stack_a);
	if (!is_sorted(*stack_a))
		three_sort(stack_a);
	while (*stack_b)
	{
		init_list(stack_a, stack_b);
		move_back(stack_a, stack_b);
	}
	final_sort(stack_a);
}

void	final_sort(t_node **stack_a)
{
	t_node	*smallest;

	smallest = get_minimum_node(*stack_a);
	while (*stack_a != smallest)
	{
		if (smallest->index <= ft_node_size(*stack_a) / 2)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
}
