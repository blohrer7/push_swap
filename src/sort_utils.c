/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:12:20 by blohrer           #+#    #+#             */
/*   Updated: 2025/03/02 23:22:39 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*get_lowest_cost(t_node *stack)
{
	t_node	*current;
	t_node	*lowest;

	current = stack;
	lowest = stack;
	while (current)
	{
		if (current->price < lowest->price)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}

t_node	*get_minimum_node(t_node *list)
{
	t_node	*current;
	t_node	*min_node;

	current = list;
	min_node = list;
	while (current)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_node	*ft_node_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_free(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

void	validate_and_add(t_node **stack, char *arg)
{
	long	value;
	t_node	*new_node;

	if (!arg || !*arg || !is_number(arg))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	value = ft_atol(arg);
	if (value < INT_MIN || value > INT_MAX || has_duplicates(*stack,
			(int)value))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	new_node = ft_node_new((int)value);
	if (!new_node)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	ft_node_add_back(stack, new_node);
}
