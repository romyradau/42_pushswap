/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_rank.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:52:30 by rschleic          #+#    #+#             */
/*   Updated: 2021/11/16 15:37:35 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_give_rank(t_node *current)
{
	t_node	*compare_to;

	compare_to = current->next;
	while (1)
	{
		if (current->n > compare_to->n)
			current->rank++;
		compare_to = compare_to->next;
		if (current == compare_to)
			break ;
	}
}

void	ft_rank(t_stack *a)
{
	t_node	*current;

	current = a->head;
	while (1)
	{
		ft_give_rank(current);
		current = current->next;
		if (current == a->head)
			break ;
	}
}

void	ft_rank_new(t_node *current, t_stack *a)
{
	while (1)
	{
		current->rank--;
		current = current->next;
		if (current == a->head)
			break ;
	}
}
