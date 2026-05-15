/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 18:36:15 by labia-fe          #+#    #+#             */
/*   Updated: 2026/05/15 18:36:16 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

//		[CHECKER FUNCTIONS]

void	free_matrix(char **mtrx);
int		move_check(t_stack **stack_a, t_stack **stack_b, char *move);

//		[MOVEMENT FUNCTIONS]

t_stack	*swap(t_stack **stack, char id, int print);
t_stack	*rotate(t_stack **stack, char id, int print);
t_stack	*rev_rotate(t_stack	**stack, char id, int print);
void	push(t_stack **src, t_stack **dst, char id, int print);

#endif
