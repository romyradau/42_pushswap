/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:22:35 by rschleic          #+#    #+#             */
/*   Updated: 2021/11/16 16:57:42 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (ft_create_cdll(argv, a, b) == 1)
		return (1);
	if (a->size <= 5)
		ft_sort_small_stack(a, b);
	if (stack_is_sorted(a))
	{
		del_stack(&b);
		del_stack(&a);
		return (0);
	}
	ft_presort(a, b, ft_achim(a));
	while (b->size > 0)
		ft_rentability(a, b);
	ft_make_smallest_head(a, b);
	del_stack(&b);
	del_stack(&a);
	return (0);
}
