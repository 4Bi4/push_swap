/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 18:35:44 by labia-fe          #+#    #+#             */
/*   Updated: 2026/05/15 18:35:45 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//	Auxiliary function for move_check().
//	Checks if the move is valid and applies it to the stacks
//	(norminette wouldn't allow a long function)
//	\returns
//	0 if valid, 1 if invalid
static int	move_check_2(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (ft_strncmp(move, "ra\n", 4) == 0)
		*stack_a = rotate(stack_a, 'a', 0);
	else if (ft_strncmp(move, "rb\n", 4) == 0)
		*stack_b = rotate(stack_b, 'b', 0);
	else if (ft_strncmp(move, "rr\n", 4) == 0)
	{
		*stack_a = rotate(stack_a, 'a', 0);
		*stack_b = rotate(stack_b, 'b', 0);
	}
	else if (ft_strncmp(move, "rra\n", 5) == 0)
		*stack_a = rev_rotate(stack_a, 'a', 0);
	else if (ft_strncmp(move, "rrb\n", 5) == 0)
		*stack_b = rev_rotate(stack_b, 'b', 0);
	else if (ft_strncmp(move, "rrr\n", 5) == 0)
	{
		*stack_a = rev_rotate(stack_a, 'a', 0);
		*stack_b = rev_rotate(stack_b, 'b', 0);
	}
	else
		return (1);
	return (0);
}

//	Checks if the move is valid and applies it to the stacks
//	\returns
//	0 if valid, 1 if invalid
int	move_check(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (ft_strncmp(move, "sa\n", 4) == 0)
		*stack_a = swap(stack_a, 'a', 0);
	else if (ft_strncmp(move, "sb\n", 4) == 0)
		*stack_b = swap(stack_b, 'b', 0);
	else if (ft_strncmp(move, "ss\n", 4) == 0)
	{
		*stack_a = swap(stack_a, 'a', 0);
		*stack_b = swap(stack_b, 'b', 0);
	}
	else if (ft_strncmp(move, "pa\n", 4) == 0)
		push(stack_b, stack_a, 'a', 0);
	else if (ft_strncmp(move, "pb\n", 4) == 0)
		push(stack_a, stack_b, 'b', 0);
	else if (move_check_2(stack_a, stack_b, move) != 0)
		return (1);
	return (0);
}
