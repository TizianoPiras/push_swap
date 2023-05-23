/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpiras <tpiras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:47:17 by tpiras            #+#    #+#             */
/*   Updated: 2023/05/23 17:44:53 by tpiras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./push_swap.h"
# include "get_next_line/get_next_line.h"

void	iterate(t_stack **a, t_stack **b, char *str);
int		checking_stack(t_stack *stack);
int		main(int argc, char **argv);
void	check_rotate(t_stack **a, t_stack **b, char *str);
void	stamp(t_stack *stack);

#endif