/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertiz <ertiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:42:24 by tpiras            #+#    #+#             */
/*   Updated: 2023/05/27 20:25:44 by ertiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**matrix;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		matrix = ft_split(av[1], ' ');
		stack_init(&a, matrix, 2);
	}
	if (ac > 2)
		stack_init(&a, av + 1, 0);
	iterate(&a, &b, get_next_line(0));
	free_stack(&a);
	return (0);
}

void	iterate(t_stack **a, t_stack **b, char *str)
{
	while (str)
	{
		if (ft_strncmp(str, "pa", 2) == 0)
			pa(a, b, true);
		else if (ft_strncmp(str, "pb", 2) == 0)
			pb(b, a, true);
		else if (ft_strncmp(str, "sa", 2) == 0)
			sa(a, true);
		else if (ft_strncmp(str, "sb", 2) == 0)
			sb(b, true);
		else if (ft_strncmp(str, "ss", 2) == 0)
			ss(a, b, true);
		else
			check_rotate(a, b, str);
		free(str);
		str = get_next_line(0);
	}
	stamp(*a);
}

void	check_rotate(t_stack **a, t_stack **b, char *str)
{
	if (ft_strncmp(str, "ra", 2) == 0)
		ra(a, true);
	else if (ft_strncmp(str, "rb", 2) == 0)
		rb(b, true);
	else if (ft_strncmp(str, "rra", 3) == 0)
		rra(a, true);
	else if (ft_strncmp(str, "rrb", 3) == 0)
		rrb(b, true);
	else if (ft_strncmp(str, "rrr", 3) == 0)
		rrr(a, b, true);
	else if (ft_strncmp(str, "rr", 2) == 0)
		rr(a, b, true);
	else
	{
		write(1, "Error: command not found\n", 25);
		write(1, "Try with:\n pb, pa, sa, sb, ss, ra, rb, rr, rra, rrb, rrr.\n", 58);
		//exit(2);
	}
}

int	checking_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < (stack_len(stack)))
	{
		if (stack->next->nbr > stack->nbr)
			return (1);
		i++;
	}
	return (0);
}

void	stamp(t_stack *stack)
{
	if (checking_stack(stack) == 1)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}
