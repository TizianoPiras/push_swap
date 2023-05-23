/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:48:04 by ertiz             #+#    #+#             */
/*   Updated: 2023/05/23 15:33:40 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	int		ng;
	long	res;

	res = 0;
	ng = 1;
	while (*str != '\0' && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str == '-')
		ng = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = (10 * res) + (*str - 48);
		str++;
	}
	return ((long)res * ng);
}

//search for the last node

t_stack	*find_last_node(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

//put a node in the stack next to the last member

void	append_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->nbr = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = find_last_node(*stack);
		last->next = node;
		node->prev = last;
	}
}

//Stack creator, flag useful -> if true the av is in the HEAP to free.

void	stack_init(t_stack **a, char **av, int flag_ac2)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]) == 1)
		{
			write(2, "Error: please insert only number, better with \" \"\n", 50);
			if (flag_ac2 == 2)
				free_matrix(av);
			exit(2);
		}
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, av, flag_ac2);
		if (error_repetation(*a, (int)nbr))
			error_free(a, av, flag_ac2);
		append_node(a, nbr);
		i++;
	}
	if (flag_ac2 == 2)
		free_matrix(av);
}
