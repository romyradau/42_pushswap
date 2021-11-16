/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:42:25 by rschleic          #+#    #+#             */
/*   Updated: 2021/11/16 17:26:07 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

void	ft_wrong_command(t_stack *a, t_stack *b, char *command)
{
	write(2, "Error\n", 6);
	free(command);
	del_stack(&a);
	del_stack(&b);
	exit(EXIT_FAILURE);
}

void	ft_which_command(t_stack *a, t_stack *b, char *command)
{
	if (!ft_strncmp(command, "sa\n", 3))
		ft_swap(a, NULL);
	else if (!ft_strncmp(command, "sb\n", 3))
		ft_swap(b, NULL);
	else if (!ft_strncmp(command, "ss\n", 3))
		ft_double_swap(a, b, NULL);
	else if (!ft_strncmp(command, "pa\n", 3))
		ft_push(b, a, NULL);
	else if (!ft_strncmp(command, "pb\n", 3))
		ft_push(a, b, NULL);
	else if (!ft_strncmp(command, "ra\n", 3))
		ft_rotate(a, NULL);
	else if (!ft_strncmp(command, "rb\n", 3))
		ft_rotate(b, NULL);
	else if (!ft_strncmp(command, "rr\n", 3))
		ft_double_rotate(a, b, NULL);
	else if (!ft_strncmp(command, "rra\n", 4))
		ft_reverse_rotate(a, NULL);
	else if (!ft_strncmp(command, "rrb\n", 4))
		ft_reverse_rotate(b, NULL);
	else if (!ft_strncmp(command, "rrr\n", 4))
		ft_double_r_rotate(a, b, NULL);
	else
		ft_wrong_command(a, b, command);
}

void	ft_check_commands(t_stack *a, t_stack *b)
{
	char	*command;

	while (1)
	{
		command = get_next_line(0);
		if (command == NULL)
			break ;
		ft_which_command(a, b, command);
		free(command);
	}
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		return (0);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (ft_create_cdll(argv, a, b) == 1)
		return (1);
	ft_check_commands(a, b);
	if (stack_is_sorted(a) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	del_stack(&a);
	del_stack(&b);
	return (0);
}
