/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:50:53 by blohrer           #+#    #+#             */
/*   Updated: 2025/02/28 10:40:15 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//  ================== STACK-DATENSTRUKTUREN ==================

typedef struct s_node
{
	int				value;
	int				index;
	int				median;
	int				price;
	int				cheapest;
	struct s_node	*target;
	struct s_node	*next;
}					t_node;

//  ================== STACK INITIaTION ==================

void				cur_indexes(t_node **stack);
void				assign_targets(t_node *stack_a, t_node *stack_b);
void				calculate_move_costs(t_node *stack_a, t_node *stack_b);
void				cheapest_move(t_node *stack);
void				init_list(t_node **stack_a, t_node **stack_b);

//  ================== PUSH-OPERATIONEN ==================

void				push_a(t_node **stack_a, t_node **stack_b);
void				push_b(t_node **stack_b, t_node **stack_a);
void				push_to_stack(t_node **dest, t_node **src,
						const char *operation);

//  ================== ROTIEREN & REVERSE ==================

void				rotate_a(t_node **stack_a);
void				rotate_b(t_node **stack_b);
void				rotate_both(t_node **stack_a, t_node **stack_b);
void				rotate_stack(t_node **stack, const char *operation);
void				reverse_rotate_a(t_node **stack_a);
void				reverse_rotate_b(t_node **stack_b);
void				reverse_rotate_both(t_node **stack_a, t_node **stack_b);
void				reverse_rotate_stack(t_node **stack, const char *operation);

//  ================== SWAP ==================

void				swap_a(t_node **stack_a);
void				swap_b(t_node **stack_b);
void				swap_both(t_node **stack_a, t_node **stack_b);
void				swap_top(t_node **stack, const char *operation);

//  ================== ARGS_CHECK ==================

void				parse_arguments(int argc, char *argv[], t_node **stack);
void				validate_and_add(t_node **stack, char *arg);
void				clear(t_node **stack_a, t_node **stack_b);
int					has_duplicates(t_node *stack, int value);
void				print_stack(t_node *stack);

//  ================== SORT UTILS ==================

t_node				*get_lowest_cost(t_node *stack);
t_node				*get_minimum_node(t_node *stack);
void				ft_free(char **numbers);

//  ================== ERROR ==================

int					is_number(char *str);
long				ft_atol(const char *str);
void				free_errors(t_node **stack);

//  ================== NODE ==================

t_node				*ft_node_new(int value);
void				ft_node_add_back(t_node **lst, t_node *new);
void				ft_node_add_front(t_node **lst, t_node *new);
void				ft_node_clear(t_node **lst);
int					ft_node_size(t_node *lst);
t_node				*ft_node_last(t_node *lst);

//  ================== SORTING ==================

int					is_sorted(t_node *list);
void				sort_stack(t_node **stack_a, t_node **stack_b);
void				execute_best_move(t_node **stack_a, t_node **stack_b);
void				three_sort(t_node **stack);
void				init_position(t_node **stack);

//  ================== BIG SORT ==================

void				big_sort(t_node **stack_a, t_node **stack_b);
void				final_sort(t_node **stack_a);
void				move_back(t_node **stack_a, t_node **stack_b);
void				position_in_a(t_node **stack_a, t_node *cheapest);
void				position_in_b(t_node **stack_b, t_node *cheapest);

#endif
