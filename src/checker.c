/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 18:36:21 by labia-fe          #+#    #+#             */
/*   Updated: 2026/05/15 18:36:22 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//	Loads Stack A with the revieced args
//	\returns
//	1 if ok, 0 if error
static int	load_stack(t_stack **stack_a, char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (str_check(stack_a, argv[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

//	Reads the moves from stdin and 
//	replays them onto the stacks
//	\returns
//	0 if ok, 1 if error
static int	apply_moves(t_stack **stack_a, t_stack **stack_b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (move_check(stack_a, stack_b, move) != 0)
		{
			write(2, "Error\n", 7);
			return (free(move), 1);
		}
		free(move);
		move = get_next_line(0);
	}
	return (0);
}

//	Main function for the checker program
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (load_stack(&stack_a, argv, argc) != 0)
		return (free_list(&stack_a), free_list(&stack_b), 1);
	if (dup_check(&stack_a) != 0)
		return (free_list(&stack_a), free_list(&stack_b), 1);
	indexer(stack_a);
	if (apply_moves(&stack_a, &stack_b) != 0)
		return (free_list(&stack_a), free_list(&stack_b), 1);
	if (is_sorted(&stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_list(&stack_a), free_list(&stack_b), 0);
}
