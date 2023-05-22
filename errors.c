/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:51:20 by ertiz             #+#    #+#             */
/*   Updated: 2023/05/22 18:56:15 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//free all the elements of the matrix argv

void	free_matrix(char **av)
{
	int	i;

	i = -1;
	if (*av == NULL || av == NULL)
		return ;
	while (av[i])
		free(av[i++]);
	free(av - 1);
}

//free all elements of the stack

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

//check if there is error on syntax or 
//there are letters in the input string (not valid)

int	error_syntax(char *str_nbr)
{
	if (!(*str_nbr == '+' || *str_nbr == '-'
			|| (*str_nbr >= '0' && *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+' || *str_nbr == '-')
		&& !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

//simply exit the program if there are errors

void	error_free(t_stack **a, char **av, bool flag_ac2)
{
	free_stack(a);
	if (flag_ac2)
		free_matrix(av);
	write(2, "Error: please insert only number, better with \" \"\n", 50);
	exit(2);
}

//check if there is repetation in the stack of number (not legit!).

int	error_repetation(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->nbr == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
