/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:08:07 by blohrer           #+#    #+#             */
/*   Updated: 2025/02/28 10:17:29 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	cur_indexes(t_node **stack)
{
	t_node	*current_node;
	int		position;
	int		half_size;

	position = 0;
	current_node = *stack;
	half_size = ft_node_size(*stack) / 2;
	while (current_node)
	{
		current_node->index = position;
		if (position <= half_size)
			current_node->median = 1;
		else
			current_node->median = 0;
		position++;
		current_node = current_node->next;
	}
}

void	assign_targets(t_node *stack_a, t_node *stack_b)
{
	t_node	*current_a;
	t_node	*best_target;
	long	smallest_larger_value;

	while (stack_b)
	{
		smallest_larger_value = LONG_MAX;
		best_target = NULL;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < smallest_larger_value)
			{
				smallest_larger_value = current_a->value;
				best_target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_target == NULL)
			stack_b->target = get_minimum_node(stack_a);
		else
			stack_b->target = best_target;
		stack_b = stack_b->next;
	}
}

void	calculate_move_costs(t_node *stack_a, t_node *stack_b)
{
	int		size_a;
	int		size_b;
	t_node	*current;
	int		move_cost;

	size_a = ft_node_size(stack_a);
	size_b = ft_node_size(stack_b);
	current = stack_b;
	while (current)
	{
		move_cost = current->index;
		if (current->median == 0)
			move_cost = size_b - current->index;
		if (current->target->median == 1)
			move_cost += current->target->index;
		else
			move_cost += size_a - current->target->index;
		current->price = move_cost;
		current = current->next;
	}
}

void	cheapest_move(t_node *stack)
{
	t_node	*cheapest_node;
	long	cheapest_value;

	cheapest_node = NULL;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->price < cheapest_value)
		{
			cheapest_value = stack->price;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = 1;
}

void	init_list(t_node **stack_a, t_node **stack_b)
{
	cur_indexes(stack_a);
	cur_indexes(stack_b);
	assign_targets(*stack_a, *stack_b);
	calculate_move_costs(*stack_a, *stack_b);
	cheapest_move(*stack_b);
}
