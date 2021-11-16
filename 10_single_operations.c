/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_single_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:02:40 by rschleic          #+#    #+#             */
/*   Updated: 2021/11/16 22:02:49 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack, char *command)
{
	int	store_rank;
	int	store_n;

	if (stack->head == NULL)
		return ;
	store_rank = stack->head->rank;
	store_n = stack->head->n;
	stack->head->rank = stack->head->next->rank;
	stack->head->next->rank = store_rank;
	stack->head->n = stack->head->next->n;
	stack->head->next->n = store_n;
	if (command != NULL)
		write(1, command, ft_strlen(command));
}

void	ft_rotate(t_stack *stack, char *command)
{
	if (stack->head == NULL)
		return ;
	stack->head = stack->head->next;
	if (command != NULL)
		write(1, command, ft_strlen(command));
}

void	ft_reverse_rotate(t_stack *stack, char *command)
{
	if (stack->head == NULL)
		return ;
	stack->head = stack->head->prev;
	if (command != NULL)
		write(1, command, ft_strlen(command));
}

void	empty_stack(t_node *ptr, t_stack *dest)
{
	dest->head = ptr;
	ptr->next = ptr;
	ptr->prev = ptr;
}

void	ft_push(t_stack *src, t_stack *dest, char *command)
{
	t_node	*ptr;

	printf("src size:	%d\n", src->size);
	if (src->size == 1)
		return ;
	ptr = src->head;
	src->head->next->prev = src->head->prev;
	src->head->prev->next = src->head->next;
	src->head = src->head->next;
	if (dest->head == NULL)
		empty_stack(ptr, dest);
	else
	{
		ptr->next = dest->head;
		ptr->prev = dest->head->prev;
		dest->head->prev->next = ptr;
		dest->head->prev = ptr;
		dest->head = ptr;
	}
	src->size--;
	dest->size++;
	if (src->size == 0)
		src->head = NULL;
	if (command != NULL)
		write(1, command, ft_strlen(command));
}
