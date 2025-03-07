/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:29:04 by blohrer           #+#    #+#             */
/*   Updated: 2025/03/07 07:33:17 by blohrer          ###   ########.fr       */
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

void	two_sort(t_node **stack)
{
	int	a;
	int	b;

	a = (*stack)->value;
	b = (*stack)->next->value;
	if (a > b)
	{
		swap_a(stack);
		return ;
	}
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

void	parse_arguments(int argc, char *argv[], t_node **stack)
{
	char	**args;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		if (!argv[i] || !*argv[i])
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		args = ft_split(argv[i], ' ');
		if (!args || !args[0])
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		j = 0;
		while (args[j])
			validate_and_add(stack, args[j++]);
		ft_free(args);
		i++;
	}
}

void	print_stack(t_node *stack)
{
	t_node	*current;

	if (!stack)
	{
		printf("Stack ist leer.\n");
		return ;
	}
	current = stack;
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}
