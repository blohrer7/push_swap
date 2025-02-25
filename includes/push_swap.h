/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blohrer <blohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:50:53 by blohrer           #+#    #+#             */
/*   Updated: 2025/02/25 16:37:11 by blohrer          ###   ########.fr       */
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



//  ================== PUSH-OPERATIONEN ==================


//  ================== ROTIEREN & REVERSE ==================


//  ================== ALGORITHMEN ==================



//  ================== HILFSFUNKTIONEN ==================



//  ================== STACK-DEBUGGING ==================



//  ================== ARGUMENT-VALIDIERUNG ==================


#endif
