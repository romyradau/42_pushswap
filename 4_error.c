/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:07:55 by rschleic          #+#    #+#             */
/*   Updated: 2021/11/16 17:25:58 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_double_input(t_stack a)
{
	t_node	*last_inserted;
	t_node	*compare_to;

	last_inserted = a.head->prev;
	compare_to = a.head;
	while (last_inserted != compare_to)
	{
		if (last_inserted->n == compare_to->n)
			return (write(2, "Error\n", 6));
		compare_to = compare_to->next;
	}
	return (0);
}

int	ft_not_int(char	**dis, int j)
{
	int	c;

	c = 0;
	if (dis[j][c] == '-' || dis[j][c] == '+')
		c++;
	if (dis[j][c] == '\0')
		return (0);
	while (dis[j][c] != '\0')
	{
		if (dis[j][c] < '0' || dis[j][c] > '9')
			return (0);
		c++;
	}
	return (1);
}

int	error_input(char	**dis, int j)
{
	if (ft_not_int(dis, j) == 0)
		return (write(2, "Error\n", 6));
	if (((ft_atoi(dis[j]) > INT_MAX || ft_atoi(dis[j]) < INT_MIN)))
		return (write(2, "Error\n", 6));
	return (0);
}
