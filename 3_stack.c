/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:53:11 by rschleic          #+#    #+#             */
/*   Updated: 2021/11/16 17:29:21 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
}

void	del_stack(t_stack **stack)
{
	t_node	*tmp;

	if ((*stack)->head == NULL)
	{
		free(*stack);
		return ;
	}
	while ((*stack)->size)
	{
		tmp = (*stack)->head->next;
		free((*stack)->head);
		(*stack)->head = tmp;
		(*stack)->size--;
	}
	free(*stack);
	*stack = NULL;
}

int	stack_is_sorted(t_stack *a)
{
	t_node	*start;

	start = a->head;
	if (a->head == a->head->next)
		return (1);
	while (start->n < start->next->n)
	{
		start = start->next;
		if (start == a->head->prev)
			return (1);
	}
	return (0);
}

void	ft_make_smallest_head(t_stack *a, t_stack *b)
{
	t_node	*start;

	ft_index(a, b);
	start = ft_no_greater_value(a);
	if (start->index <= (a->size) / 2)
		while (start != a->head)
			ft_rotate(a, "ra\n");
	else
		while (start != a->head)
			ft_reverse_rotate(a, "rra\n");
}
