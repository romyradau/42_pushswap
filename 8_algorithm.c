/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_algorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:30:41 by rschleic          #+#    #+#             */
/*   Updated: 2021/11/16 16:07:17 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_double_execution(t_node *aN, t_node *bN, t_stack *a, t_stack *b)
{
	if (bN->index < (b->size - 1) / 2 && aN->index < (a->size - 1) / 2)
	{
		while (bN != b->head && aN != a->head)
			ft_double_rotate(a, b, "rr\n");
		while (bN != b->head)
			ft_rotate(b, "rb\n");
		while (aN != a->head)
			ft_rotate(a, "ra\n");
	}
	else if (bN->index >= (b->size - 1) / 2 && aN->index >= (a->size - 1) / 2)
	{
		while (bN != b->head && aN != a->head)
			ft_double_r_rotate(a, b, "rrr\n");
		while (bN != b->head)
			ft_reverse_rotate(b, "rrb\n");
		while (aN != a->head)
			ft_reverse_rotate(a, "rra\n");
	}
}

void	ft_execution(t_node *aN, t_node *bN, t_stack *a, t_stack *b)
{
	ft_double_execution(aN, bN, a, b);
	if (bN->index < (b->size - 1) / 2)
		while (bN != b->head)
			ft_rotate(b, "rb\n");
	else
		while (bN != b->head)
			ft_reverse_rotate(b, "rrb\n");
	if (aN->index < (a->size - 1) / 2)
		while (aN != a->head)
			ft_rotate(a, "ra\n");
	else
		while (aN != a->head)
			ft_reverse_rotate(a, "rra\n");
	ft_push(b, a, "pa\n");
}

t_node	*ft_find_spot(t_stack *a, t_node *bN)
{
	t_node	*aN;
	t_node	*best;

	aN = a->head;
	best = a->head;
	while (1)
	{
		best = ft_compare(best, aN, bN);
		aN = aN->next;
		if (aN == a->head)
			break ;
	}
	if (best->rank < bN->rank)
		return (ft_no_greater_value(a));
	return (best);
}

int	ft_moves(t_stack *a, t_stack *b, t_node	*bN)
{
	int	a_index;
	int	b_index;

	a_index = ft_find_spot(a, bN)->index;
	b_index = bN->index;
	if (a_index > (a->size - 1) / 2)
		a_index = a->size - a_index;
	if (b_index > (b->size - 1) / 2)
		b_index = b->size - b_index;
	return (a_index + b_index);
}

void	ft_rentability(t_stack *a, t_stack *b)
{
	t_node	*b_current;
	t_node	*best;

	b_current = b->head;
	best = b->head;
	ft_index(a, b);
	while (1)
	{
		if (ft_moves(a, b, best) > ft_moves(a, b, b_current))
			best = b_current;
		b_current = b_current->next;
		if (b_current == b->head)
			break ;
	}
	ft_execution(ft_find_spot(a, best), best, a, b);
}
