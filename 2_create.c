/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_create.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:44:31 by rschleic          #+#    #+#             */
/*   Updated: 2021/11/16 18:03:12 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

void	free_array(char **dis, int j)
{
	j = 0;
	while (dis[j] != NULL)
		free(dis[j++]);
	free(dis);
}

int	push_node(t_stack *a, int x)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (1);
	new_node->n = x;
	if (a->head == NULL)
	{
		a->head = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		a->head->prev->next = new_node;
		new_node->prev = a->head->prev;
		a->head->prev = new_node;
		new_node->next = a->head;
	}
	a->size++;
	return (0);
}

int	handle_input(char **argv, int i, t_stack *a)
{
	int		j;
	char	**dis;

	dis = ft_split(argv[i], ' ');
	j = 0;
	while (dis[j] != NULL)
	{
		if (error_input(dis, j))
		{
			free_array(dis, j);
			return (1);
		}
		push_node(a, ft_atoi(dis[j]));
		if (ft_double_input(*a))
		{
			free_array(dis, j);
			return (1);
		}
		j++;
	}
	free_array(dis, j);
	if (*dis == NULL)
		return (write(2, "Error\n", 6));
	return (0);
}

int	ft_create_cdll(char	**argv, t_stack *a, t_stack *b)
{
	int	i;

	init_stack(a);
	init_stack(b);
	i = 1;
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '\0')
		{
			del_stack(&b);
			del_stack(&a);
			return (1);
		}
		if (handle_input(argv, i, a))
		{
			del_stack(&a);
			del_stack(&b);
			return (1);
		}
		i++;
	}
	ft_rank(a);
	return (0);
}
