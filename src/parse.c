/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:19:54 by blohrer           #+#    #+#             */
/*   Updated: 2025/02/28 11:20:10 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	parse_arguments(int argc, char *argv[], t_node **stack)
{
	char	**args;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			return ;
		j = 0;
		while (args[j])
		{
			validate_and_add(stack, args[j]);
			j++;
		}
		ft_free(args);
		i++;
	}
}
