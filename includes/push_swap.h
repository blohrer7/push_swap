/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:50:53 by blohrer           #+#    #+#             */
/*   Updated: 2025/02/24 16:46:05 by blohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

//  ================== STACK-DATENSTRUKTUREN ==================

typedef struct s_node
{
	int value;           // Die gespeicherte Zahl
	struct s_node *next; // Zeiger auf das nächste Element im Stack
}		t_node;

typedef struct s_stack
{
	t_node *top; // Zeiger auf das oberste Element
	int size;    // Anzahl der Elemente im Stack
}		t_stack;

//  ================== STACK-OPERATIONEN ==================

t_stack	*stack_init(void);
void	stack_push(t_stack *stack, int value);
void	stack_push_to(t_stack *from, t_stack *to);
int		stack_pop(t_stack *stack);
void	stack_free(t_stack **stack);
void	sa(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void sb(t_stack *b);

//  ================== PUSH-OPERATIONEN ==================

void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);

//  ================== ROTIEREN & REVERSE ==================

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//  ================== ALGORITHMEN ==================

void	radix_sort(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	sort_large(t_stack *a, t_stack *b);
void	sort_chunks(t_stack *a, t_stack *b);
void	push_chunk_to_b(t_stack *a, t_stack *b, int lower, int upper);

//  ================== HILFSFUNKTIONEN ==================

int compare_ints(const void *a, const void *b);
int find_nth_smallest(t_stack *stack, int n);
int find_position_in_stack(t_stack *stack, int value);
int stack_len(t_stack *stack);
int get_biggest(t_stack *stack);
int get_smallest(t_stack *stack);
t_node *get_last_node(t_stack *stack);
t_node *get_before_last_node(t_stack *stack);
void print_stack(t_stack *stack, char *name);
int	find_min_index(t_stack *stack);
t_node	*stack_get_pre_tail(t_stack *stack);
t_node	*stack_get_tail(t_stack *stack);
int	stack_get_lowest(t_stack *stack);
int	stack_get_highest(t_stack *stack);
void	final_fix(t_stack *a);
void	push_min_to_a(t_stack *a, t_stack *b);
void	push_max_to_a(t_stack *a, t_stack *b);
void sort_before_pa(t_stack *b);
void optimize_pa(t_stack *a, t_stack *b);
void sort_stack(t_stack *a, t_stack *b);
t_node *find_largest(t_stack *b);
t_node *find_smallest(t_stack *b);
void quick_sort(t_stack *a, t_stack *b, int count);
void	sort_small(t_stack *a, t_stack *b);
int find_median(t_stack *stack, int size);
void quicksort_array(int *arr, int low, int high);
int partition(int *arr, int low, int high);
int find_index(t_stack *stack, int value);
int find_min_index(t_stack *a);
t_node *find_largest(t_stack *b);
t_node *find_smallest(t_stack *b);
int		is_sorted(t_stack *stack);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
int		find_value(t_stack *stack, int value);
int	find_position(t_stack *stack, int value);
void	optimize_rotations(t_stack *a, t_stack *b);
void	optimize_pushes(t_stack *a, t_stack *b);
void	process_bit(t_stack *a, t_stack *b, int bit);

//  ================== STACK-DEBUGGING ==================

void	verify_sorted_stack(t_stack *a, int expected_size);

//  ================== ARGUMENT-VALIDIERUNG ==================

char	**parse_args(int argc, char *argv[], int *new_argc, int *use_split);
void	free_args(char **args, int use_split);
int		is_number(char *str);
int		is_int_range(char *str);
int		has_duplicates(char **args, int argc);
int		validate_args(char **args, int argc);

#endif
