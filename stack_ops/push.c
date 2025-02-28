/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:33:20 by blohrer           #+#    #+#             */
/*   Updated: 2025/02/28 09:19:41 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_stack(t_node **dest, t_node **src, const char *operation)
{
	t_node	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = NULL;
	ft_node_add_front(dest, temp);
	ft_printf("%s\n", operation);
}

void	push_a(t_node **stack_a, t_node **stack_b)
{
	push_to_stack(stack_a, stack_b, "pa");
}

void	push_b(t_node **stack_b, t_node **stack_a)
{
	push_to_stack(stack_b, stack_a, "pb");
}
