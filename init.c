/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:31:18 by ertiz             #+#    #+#             */
/*   Updated: 2023/05/23 15:31:25 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(t_stack *stack)
{
	int	i;
	int	center;

	i = 0;
	if (stack == NULL)
		return ;
	center = stack_len(stack) / 2;
	while (stack)
	{
		stack->act_index = i;
		if (i <= center)
			stack->ab_median = true;
		else
			stack->ab_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_index;

	while (b)
	{
		best_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_index)
			{
				best_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_index == LONG_MAX)
			b->target_node = is_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target(a, b);
	node_evaluation(a, b);
	set_cheapest(b);
}
