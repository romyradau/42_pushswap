/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:57:02 by rschleic          #+#    #+#             */
/*   Updated: 2021/11/16 16:31:33 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_node{
	int				n;
	int				rank;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack{
	t_node	*head;
	int		size;
}	t_stack;

typedef struct s_laci{
	t_node	*start;
	int		len;
}	t_laci;

int		ft_create_cdll(char	**argv, t_stack *a, t_stack *b);
void	init_stack(t_stack *a);
void	del_stack(t_stack **stack);
int		stack_is_sorted(t_stack *a);
void	ft_index(t_stack *a, t_stack *b);
void	ft_make_smallest_head(t_stack *a, t_stack *b);
int		error_input(char	**dis, int j);
int		ft_double_input(t_stack a);
void	ft_give_rank(t_node *current);
void	ft_rank(t_stack *a);
void	ft_rank_new(t_node *current, t_stack *a);
void	ft_sort_small_stack(t_stack *a, t_stack *b);
t_laci	ft_achim(t_stack *a);
void	ft_presort(t_stack *a, t_stack *b, t_laci achim);
void	ft_rentability(t_stack *a, t_stack *b);
t_node	*ft_no_greater_value(t_stack *a);
t_node	*ft_compare(t_node *a_best, t_node *a_element, t_node *b_element);
void	ft_swap(t_stack *stack, char *command);
void	ft_rotate(t_stack *stack, char *command);
void	ft_reverse_rotate(t_stack *stack, char *command);
void	ft_push(t_stack *a, t_stack *b, char *command);
void	ft_double_swap(t_stack *a, t_stack *b, char *command);
void	ft_double_rotate(t_stack *a, t_stack *b, char *command);
void	ft_double_r_rotate(t_stack *a, t_stack *b, char *command);

#endif