/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:23:40 by rschleic          #+#    #+#             */
/*   Updated: 2021/11/16 15:12:03 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_achim_length(t_node *start)
{
	int	length;

	length = 0;
	while (start->n < start->next->n)
	{
		length++;
		start = start->next;
	}
	return (length);
}

t_laci	ft_achim(t_stack *a)
{
	t_node	*current;
	t_laci	laci;
	int		i;

	current = a->head;
	laci.len = 0;
	laci.start = a->head;
	while (current->next != laci.start)
	{
		i = 0;
		if (ft_achim_length(current) > laci.len)
		{
			laci.len = ft_achim_length(current);
			laci.start = current;
			while (i < laci.len)
			{
				current = current->next;
				i++;
			}
		}
		current = current->next;
	}
	return (laci);
}

void	ft_lift_push(t_stack *a, t_stack *b, t_node *current)
{
	ft_index(a, b);
	if (current->index < (a->size - 1) / 2)
		while (current != a->head)
			ft_rotate(a, "ra\n");
	else
		while (current != a->head)
			ft_reverse_rotate(a, "rra\n");
	ft_push(a, b, "pb\n");
}

void	ft_presort(t_stack *a, t_stack *b, t_laci achim)
{
	t_node	*current;
	int		chunk;
	int		i;
	int		size;

	chunk = 0;
	size = a->size;
	while (a->size > achim.len + 1)
	{
		i = 0;
		current = achim.start;
		while (i++ <= achim.len)
			current = current->next;
		chunk = chunk + size / 4;
		while (current != achim.start)
		{
			if (current->rank <= chunk)
			{
				current = current->next;
				ft_lift_push(a, b, current->prev);
			}
			else
				current = current->next;
		}
	}
}
