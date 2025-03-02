/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:29:04 by blohrer           #+#    #+#             */
/*   Updated: 2025/03/02 14:42:49 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_node *list)
{
	if (!list)
		return (1);
	while (list->next)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
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

void	three_sort(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && a > c)
		rotate_a(stack);
	if (b > c && b > a)
		reverse_rotate_a(stack);
	if ((*stack)->value > (*stack)->next->value)
		swap_a(stack);
}
