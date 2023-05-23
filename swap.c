/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:24:51 by ertiz             #+#    #+#             */
/*   Updated: 2023/05/21 10:31:48 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	if (*head == NULL || head == NULL)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next =(*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack **a, bool check)
{
	swap(a);
	if(!check)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool check)
{
	swap(b);
	if(!check)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool check)
{
	swap(a);
	swap(b);
	if(!check)
		write(1, "ss\n", 3);
}