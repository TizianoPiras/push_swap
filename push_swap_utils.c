/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:23:27 by ertiz             #+#    #+#             */
/*   Updated: 2023/05/22 19:04:06 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_evaluation(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->value = b->act_index;
		if (!(b->ab_median))
			b->value = len_b - (b->act_index);
		if (b->target_node->ab_median)
			b->value += b->target_node->act_index;
		else
			b->value += len_a - (b->target_node->act_index);
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	long	best_match;
	t_stack	*best_match_node;

	if (b == NULL)
		return ;
	best_match = LONG_MAX;
	while (b)
	{
		if (b->value < best_match)
		{
			best_match = b->value;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

t_stack	*return_cheapest(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_stack *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}
