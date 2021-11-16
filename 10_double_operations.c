/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:39:06 by rschleic          #+#    #+#             */
/*   Updated: 2021/11/16 00:00:21 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_double_swap(t_stack *a, t_stack *b, char *command)
{
	ft_swap(a, NULL);
	ft_swap(b, NULL);
	if (command != NULL)
		write(1, command, ft_strlen(command));
}

void	ft_double_rotate(t_stack *a, t_stack *b, char *command)
{
	ft_rotate(a, NULL);
	ft_rotate(b, NULL);
	if (command != NULL)
		write(1, command, ft_strlen(command));
}

void	ft_double_r_rotate(t_stack *a, t_stack *b, char *command)
{
	ft_reverse_rotate(a, NULL);
	ft_reverse_rotate(b, NULL);
	if (command != NULL)
		write(1, command, ft_strlen(command));
}
