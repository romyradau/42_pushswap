/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_small_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:26:03 by rschleic          #+#    #+#             */
/*   Updated: 2021/11/16 16:30:21 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack *a)
{
	if (a->head->n > a->head->next->n)
		ft_swap(a, "sa\n");
}

void	ft_sort_three(t_stack *a)
{
	int	o;
	int	b;
	int	c;

	o = a->head->n;
	b = a->head->next->n;
	c = a->head->prev->n;
	if (o > b && b > c)
	{
		ft_rotate(a, "ra\n");
		ft_swap(a, "sa\n");
	}
	else if (b > c && c < o)
		ft_reverse_rotate(a, "rra\n");
	else if (o > b && b < c && c > o)
		ft_swap(a, "sa\n");
	else if (b > c && c > o)
	{
		ft_reverse_rotate(a, "rra\n");
		ft_swap(a, "sa\n");
	}
	else if (b < c && c < o)
		ft_rotate(a, "ra\n");
}

void	ft_sort_four(t_stack *a, t_stack *b)
{
	ft_make_smallest_head(a, b);
	ft_push(a, b, "pb\n");
	ft_sort_three(a);
	ft_push(b, a, "pa\n");
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	ft_make_smallest_head(a, b);
	ft_push(a, b, "pb\n");
	ft_make_smallest_head(a, b);
	ft_push(a, b, "pb\n");
	ft_sort_three(a);
	ft_push(b, a, "pa\n");
	ft_push(b, a, "pa\n");
}

void	ft_sort_small_stack(t_stack *a, t_stack *b)
{
	if (stack_is_sorted(a))
		return ;
	else if (a->size == 2)
		ft_sort_two(a);
	else if (a->size == 3)
		ft_sort_three(a);
	else if (a->size == 4)
		ft_sort_four(a, b);
	else if (a->size == 5)
		ft_sort_five(a, b);
}
