/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:48:31 by ertiz             #+#    #+#             */
/*   Updated: 2023/05/21 12:28:58 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->ab_median && cheapest_node->target_node->ab_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->ab_median) &&
        !(cheapest_node->target_node->ab_median))
		rev_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b, false);
}

void	finish_rotation(t_stack **stack, t_stack *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->ab_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top->ab_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}

void    push_swap(t_stack **a, t_stack **b)
{
    t_stack *smallest;
    int     len_a;

    len_a = stack_len(*a);
    if (len_a == 5)
        handle_five(a, b);
    else
    {
        while (len_a-- > 3)
            pb(b, a, false);
    }
    sorty(a);
    while (*b)
    {
        init_nodes(*a, *b);
        move_nodes(a, b);
    }
    set_current_position(*a);
    smallest = is_smallest(*a);
    if (smallest->ab_median)
        while (*a != smallest)
            ra(a, false);
    else
        while (*a != smallest)
            rra(a, false);
}