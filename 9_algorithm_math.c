/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_math.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:30:12 by rschleic          #+#    #+#             */
/*   Updated: 2021/11/16 14:52:51 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_no_greater_value(t_stack *a)
{
	t_node	*smallest;
	t_node	*compare_to;

	smallest = a->head;
	compare_to = a->head->next;
	while (1)
	{
		if (smallest->rank > compare_to->rank)
			smallest = compare_to;
		compare_to = compare_to->next;
		if (compare_to == a->head)
			break ;
	}
	return (smallest);
}

int	ft_absolut(int n)
{
	if (n < 0)
	{
		n *= -1;
	}
	return (n);
}

t_node	*ft_compare(t_node *a_best, t_node *aN, t_node *bN)
{
	int	diff;
	int	diff_best;

	diff = bN->rank - aN->rank;
	diff_best = bN->rank - a_best->rank;
	if ((diff < 0 && diff_best < 0) && diff > diff_best)
		return (aN);
	else if ((diff > 0 && diff_best > 0) && diff < diff_best)
		return (aN);
	else if ((ft_absolut(diff) == ft_absolut(diff_best) && diff < 0))
		return (aN);
	else if (diff < 0 && diff_best > 0)
		return (aN);
	else
		return (a_best);
}

void	ft_index(t_stack *a, t_stack *b)
{
	int		i;
	t_node	*current;

	i = 0;
	current = a->head;
	while (1)
	{
		current->index = i;
		current = current->next;
		i++;
		if (current == a->head)
			break ;
	}
	i = 0;
	current = b->head;
	while (1 && current != NULL)
	{
		current->index = i;
		current = current->next;
		i++;
		if (current == b->head)
			break ;
	}
}
